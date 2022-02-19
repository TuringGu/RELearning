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
	;12.25F
	;1100.01
	;1.10001 * 2^3
	;sign bit (1 bit): 0
	;exponent bit(8 bit): 10000010
	;mantissa(23 bit): 10001000 00000000 0000000

	mov eax,eax
main ENDP
END main

;float
;add 'F' behind the instruction
;FSUB  FADD  FST ...