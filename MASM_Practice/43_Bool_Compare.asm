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
	mov eax,18
	mov ebx,26
	xor eax,ebx

	test al,10

	cmp al,10

	;Exit
	push 0
	call ExitProcess
	add esp,4

main ENDP
END main

;test: like AND, but only modify flag register value (zero flag), 
;eflags


;cmp: only modify flag register value 
;cmp a,b   (a, b are unsigned number, a - b)
;a<b, zf=0 cf=1 sf != of
;a>b, zf=0 cf=0 sf = of
;a=b, zf=1 cf=0 
;zf: Zero Flag    cf: Carry Flag    sf: Symbol Flag    of: Overflow Flag
