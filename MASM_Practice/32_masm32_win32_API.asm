.586
.MODEL flat,stdcall
option casemap:none

include windows.inc
include user32.inc
include kernel32.inc
includelib user32.lib
includelib kernel32.lib

.data 
text db "hello",0

.code
main PROC
	push 0
	push offset text
	push offset text
	push 0
	call MessageBox
	add esp,16  ;Stack Balance
	;INVOKE MessageBox,0,offset text,offset text,0

	INVOKE ExitProcess,0
main ENDP
END main