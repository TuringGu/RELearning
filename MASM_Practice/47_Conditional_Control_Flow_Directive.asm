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
	;if-else
	mov eax,4
	.if eax > i
	inc eax
	.elseif eax < i
	add eax,2
	.else
	dec eax
	.endif

	;while
	mov eax,0
	.while eax < 10
	inc eax
	.endw

	;repeat-until
	mov eax,0
	.repeat
	inc eax
	.until eax > 10

	;Exit
	push 0
	call ExitProcess
	add esp,4

main ENDP
END main

;Directive
;masm
;if else elseif endif
;==  !==  >  >=  <  <=  &  |  !
;CARRY ? 
;overflow ?
;.while  
;.repeat .until