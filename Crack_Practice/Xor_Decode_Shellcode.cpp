void main()
{
	__asm int 3  // break
	__asm
	{
			nop
			nop
			nop
			nop
			nop
			nop
			pop eax
			add eax, 0x14
			xor ecx,ecx
decode_loop:
			mov bl,[eax+ecx]
			xor bl, 0x44
			mov [eax+ecx],bl
			
			inc ecx
			cmp bl,0x90 // Ende
			jne decode_loop
			nop
			nop
			nop
			nop
			nop
	}
}
