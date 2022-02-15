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
num01 dword 5

.code
main PROC
	mov eax,5
	mov ebx,6
	add eax,ebx

	mov eax,7
	mov ebx,6
	sub eax,ebx

	;Exit
	push 0
	call ExitProcess
	add esp,4

main ENDP
END main


;add
;add eax,ecx

;sub
;sub eax,ecx

;++
;inc eax

;--
;dec eax

;neg
;neg mem
