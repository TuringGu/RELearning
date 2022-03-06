void main()
{   
	_asm{
		nop
		nop
		nop
		nop
		nop
		nop
		nop

		CLD
		PUSH 0x1e380a6a	 // hash of "messageboxA" function name
		PUSH 0x4fd18963  // hash of "ExitProcess" function name
		PUSH 0x0c917432  // hash of "LoadLibraryA" function name
		mov esi,esp
		lea edi,[esi-0xC]

		xor ebx,ebx
		mov bh,0x4	// avoid zero fill register
		sub esp,ebx

		// push string "user32"
		mov bx,0x3233
		push ebx
		push 0x72657375
		push esp
		xor edx,edx

		mov ebx,fs:[edx + 0x30]	// PEB = TEB + 0x30
		mov ecx,[ebx + 0x0C]    // PBRDRdata = PEB + 0x0C
		mov ecx,[ecx + 0x1C]    // Header pointer of module initialization table = PBRDRdata + 0x1C
		mov ecx,[ecx]           // List Entry {Blink, Flink}
		mov ebp,[ecx + 0x08]    // Kernel32.dll base address, _LDR_DATA_TABLE_ENTRY == 0x08

find_lib_functions:
		lodsd
		cmp eax,0x1e380a6a	// "messagebox"
		jne find_functions
		xchg eax,ebp
		call [edi - 0x8]
		xchg eax,ebp

find_functions:
		pushad
		mov eax,[ebp + 0x3C]  // PE Header = module address + 0x3C
		mov ecx,[ebp + eax + 0x78]  // Output Table = PE Header + 0x78
		add ecx,ebp	// Get output table absolute address
		mov ebx,[ecx + 0x20] // RVA of name table
		add ebx,ebp // Get Name table absolute address
		xor edi,edi

next_function_loop:
		inc edi
		mov esi,[ebx + edi * 4] // Get module name RVA
		add esi,ebp  // Get module name absolute address
		cdq

hash_loop:	// traversal hash of func name
		movsx eax,byte ptr[esi]
		cmp al,ah
		jz compare_hash
		ror edx,7
		add edx,eax
		inc esi
		jmp hash_loop

compare_hash:
		cmp edx,[esp + 0x1C]
		jnz next_function_loop
		mov ebx,[ecx + 0x24]	// Serial number talbe
		add ebx,ebp
		mov di,[ebx + 2 * edi]  // Save the serial number table address
		mov ebx,[ecx + 0x1C]	// Address table RVA
		add ebx,ebp	// address table absolute address
		add ebp,[ebx + 4 * edi]
		xchg eax,ebp
		pop edi
		stosd
		push edi
		popad

		cmp eax,0x1e380a6a
		jne find_lib_functions

function_call:
		xor ebx,ebx
		push ebx
		push 0x66666666
		push 0x66666666
		mov eax,esp
		push ebx
		push eax
		push eax
		push ebx
		call [edi - 0x04]  // Call MessageboxA
		push ebx
		call [edi - 0x08]  // Call ExitProcess
		
		nop
		nop
		nop
		nop
		nop
		nop
		nop
	}

}