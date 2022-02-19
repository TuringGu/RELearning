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

;Define function by directive
myFunc PROTO dwExitCode:DWORD

.data 

.code
main PROC
	;INVOKE
	INVOKE ExitProcess,0

	;INVOKE EXitProcess,ADDR myArr

main ENDP
END main
