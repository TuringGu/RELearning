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
	xor eax,eax
	xor ebx,ebx
	mov al,3h
	mov bl,4h
	mul bl

	;imul reg,reg
	imul eax,ebx

	;imul reg,reg,imm
	imul edx,eax,10

	;div
	mov ax,10
	mov bl,3
	div bl

	;idiv
	xor eax,eax
	xor ebx,ebx
	xor edx,edx
	mov al,val01
	cwd    ;extend sign of al to ah
	mov bl,+3
	idiv bl


	;Exit
	push 0
	call ExitProcess
	add esp,4

main ENDP
END main

;unsigned: mul  div
;signed: imul  idiv

;Multiplier: bl  bx  ebx
;Multiplicand: al  ax  eax

;Divisor  Dividend  quotient  remainder
;Dividend of bit is 2 times as Divisor
;div meg/reg
;
;16 bit
;Divident: dx:ax
;Divisor: oprd
;quotient: al  
;remainder: ah

;CDQ
;eax=ffffff9bh
;cdq
;edx:eax
;edx=ffffffffh
;ffffffffffffff9bh

;cbw cwd