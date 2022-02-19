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

.code
main PROC
	;loop
	mov eax,0
	mov ecx,5
lp01:
	inc eax
	loop lp01

	;loopz
	mov eax,1
	mov ecx,5
lpe01:
	dec eax
	loopz lpe01

	;Exit
	push 0
	call ExitProcess
	add esp,4

main ENDP
END main

;loop
;ecx--, ecx != 0 
;loopz, loope(usually be used in cmp)
;ecx--, ecx != 0 && zf = 1
;loopnz, loopne(usually be used in cmp)
;ecx--, ecx != 0 && zf = 0