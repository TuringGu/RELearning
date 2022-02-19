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
source byte "who am i?",0
target byte sizeof source dup(0)

.code
main PROC
	xor eax,eax

	inc eax
	jmp lp    ;jmp
	inc eax
lp:
	inc eax
	mov ecx,10
lp2:
	inc eax
	loop lp2    ;loop

	;array copy
	mov esi,0
	mov ecx,sizeof source
lp3:
	mov al,source[esi]
	mov target[esi],al
	inc esi
	loop lp3

	;Exit
	push 0
	call ExitProcess
	add esp,4

main ENDP
END main