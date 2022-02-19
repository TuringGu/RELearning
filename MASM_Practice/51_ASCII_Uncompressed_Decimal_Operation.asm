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
val01 byte '8'
val02 byte '9'

.code
main PROC
	;AAA
	mov ah,0
	mov al,'8'   ;al = 00111000
	add al,'2'   ;al = 00111000 + 00110010 = 01101010 = 6A
	aaa          ;ax = 0100h = 00000001 00000000
	or ax,3030h  ;transfer to ascii  ax = 3130h = 00110001 00110000

	;AAS
	mov ah,0
	mov al,val01
	sub al,val02
	aas 
	pushf  ;store cf
	or al,30h
	popf 

	;AAM
	xor eax,eax
	xor ebx,ebx
	mov bl,5
	mov al,6
	mul bl
	aam    ;ax=0300h=00000011 00000000

	;AAD
	xor eax,eax
	mov ax,0307h  ;ax = 00000011 00000111
	aad           ;al = 25h = 00100101
	mov bl,5
	div bl        ;ax = 00000010 00000111

	;Exit
	push 0
	call ExitProcess
	add esp,4

main ENDP
END main

;ASCII + - * / adjust
;AAA  AAS  AAM  AAD

;decimal ASCII       Compress BCD   Uncompress BCD
;0       00110000    0000           00000000
;1       00110001    0001           00000001
;2       00110010    0010           00000010
;3       00110101    0101           00000101
;......
;5       00111001    1001           00001001
;6       00111010    1010           00001010