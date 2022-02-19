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
i dword 5
val01 sbyte -16

.code
main PROC
	;al = 0FFh = 11111111
	;al = 11111111 + 11111111 = 11111110, cf = 1
	;dl = 0 + (cf=1) = 00000001
	xor eax,eax
	mov edx,edx
	mov al,0FFh
	add al,0FFh
	adc dl,0

	;00000007 00000001 - 2
	;edx = 7
	;eax = 1
	;eax = 1 - 2 = ffffffff
	;edx = 7 - (cf == 0) - 1 = 6
	;result: 00000006 ffffffff
	mov edx,7
	mov eax,1
	sub eax,2
	sbb edx,0

	;Exit
	push 0
	call ExitProcess
	add esp,4

main ENDP
END main