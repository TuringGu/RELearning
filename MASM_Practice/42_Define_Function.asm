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

;Define function
addx proc uses esi ecx
	add esi,ecx
	mov eax,esi
	ret
addx endp


main PROC
	;call function
	mov esi,5
	mov ecx,6
	push esi
	push ecx
	call addx

	
	mov eax,1

	;Exit
	push 0
	call ExitProcess
	add esp,4

main ENDP
END main

;call
;push eip
;jmp (next)

;ret
;pop eip
;jmp eip
