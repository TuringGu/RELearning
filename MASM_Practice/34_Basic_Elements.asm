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
text01 db "Input 2 numbers: "
number01 db 0
number02 db 0
format db "%d%d",0
format02 db "%d",0

.code
main PROC
	;Calculate
	mov eax,5
	add eax,6

	;Print
	push eax
	push offset format02
	call crt_printf
	add esp,8

	;Exit
	push 0
	call ExitProcess
	add esp,4

main ENDP
END main

;Integer constant
;Binary: 10101b
;Octal: 2347o
;Decimal: 2691  2691d
;Hexadecimal: 05A3h

;Real constant
;6  5.0  +3.5  -26.13E+3  15.E9

;Char & String constant
;'A'  "A"
;'whoami'  "whoami"

;Reserved word
;Instruction: mov  lea  add  sub  jcc  ...
;Register
;Attribute: db  dword
;Operator

;Identifier
;The first character is limited
;Identifier can not be the same with reserved word

;Directive
; .data  offset  ...

;Instruction
;mov eax,5    ...

;Code commets
;note:bla bla bla ...