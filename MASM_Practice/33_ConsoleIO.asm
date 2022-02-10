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
text01 db "Title Here",0
text02 db "Hello World!",0
text03 db 0
format db "%s",0

.code
main PROC
	;Pop up a window
	push 0
	push offset text01
	push offset text02
	push 0
	call MessageBox
	add esp,16	;4 parameters, each parameter occupy 32bit=32/8=4Byte, need 4*4=16Byte for balance

	;Console input & output
	push offset text03
	push offset format
	call crt_scanf
	add esp,8
	push offset text03
	call crt_printf

	;Exit
	push 0
	call ExitProcess
	add esp,4

main ENDP
END main