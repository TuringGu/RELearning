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

.code
main PROC
	mov eax,176
	shl eax,1
	
	mov eax,176
	sal eax,1

	mov eax,1
	rol al,1
	rol al,1

	clc    ;clear Flag Register
	mov bl,88h
	rcl bl,1
	rcl bl,1

	;Exit
	push 0
	call ExitProcess
	add esp,4

main ENDP
END main

;Logic shift
;11001111 -> 01100111, shift out save into CF

;Arithmetic shift
;11001111 -> 11100111, shift out save into CF

;SHL  SHR  SAL  SAR  ROL  ROR  RCL  RCR  SHLD  SHRD
;shld
;shld o1,o2,o3
;o1=11100000
;o2=10011101,  o2 provide shift bit
;o3=1
;-> o1=11000001, o1 shift out save into CF = 1