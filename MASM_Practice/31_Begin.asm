;Instruction Set(eg: .386 .486 ......)
.586  

;flat:windows program using method(code & data using same 4GB segement)    
;stdcall:calling method, when API calling the right parameter push into stack first 
.MODEL flat, stdcall  
includelib user32.lib
includelib kernel32.lib
ExitProcess PROTO, dwExitCode : DWORD
MessageBoxA PROTO hwnd : DWORD, lpText : BYTE, lpCaption : BYTE, uType : DWORD
;option casemap:none    ;case sensitive

;.data     Already initialized
;.data?    not initialize, usually as buffer zones
;.const    should not be change(write)
;.code     Where code stored 
;.stack    System will define and use it automaticly
.data
Number DWORD 0
text db "shellcode",0

.code
main proc
	mov eax,5
	mov ebx,6
	add eax,ebx
	add eax,Number
	push 0
	push offset text
	push offset text
	push 0
	call MessageBoxA
	add esp,16
	call ExitProcess
main ENDP
END main
