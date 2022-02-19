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
sourcesize = ($ - source) - 1

.code
main PROC
	;String Reverse
	mov ecx,sourcesize
	mov esi,0
lp1:
	movzx eax,source[esi]
	push eax
	inc esi
	loop lp1

	mov ecx,sourcesize
	mov esi,0
lp2:
	pop eax
	mov source[esi],al
	inc esi
	loop lp2

	;Exit
	push 0
	call ExitProcess
	add esp,4

main ENDP
END main

;32-register
;push ESP  address-4
;pop ESP  address+4

;pushfd eflags
;popfd eflags

;pushad eax ecx edx ebx esp ebp esi edi
;popad

;16-bit
;pusha
;popa