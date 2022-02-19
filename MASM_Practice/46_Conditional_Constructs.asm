.586
.MODEL flat,stdcall
option casemap:none

include windows.inc
include user32.inc
include kernel32.inc
include msvcrt.inc

includelib user32.lib
includelib kernel32.lib
includelib msvcrt.lib

.data 
dw01 dword 5
dw02 dword 6
x dword 0
y dword 0
i dword 0

.code
main PROC
	;if-else
	mov eax,dw01
	cmp eax,dw02
	jnz jnz01
	mov x,1 ;dw01 == dw02
	mov y,1
	jmp jmp01
jnz01:      ;dw01 != dw02
	mov x,2
	mov y,2
jmp01:

	;while
	mov eax,100
jmp02:
	cmp eax,i
	jle jle01
	inc i
	jmp jmp02
jle01:

	;Exit
	push 0
	call ExitProcess
	add esp,4

main ENDP
END main
