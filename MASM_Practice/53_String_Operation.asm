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
str01 byte "whoami",0
str02 byte 10 dup(?)
str03 dword 4444h
str04 dword 5555h
str05 db "ABCDEFG",0
str06 db 100 dup(?)

.code
main PROC
	cld  ;Assign 0 to the df of the flag register, make the direction of si & di forward
	
	;copy str01 to str02
	mov esi,offset str01
	mov edi,offset str02
	mov ecx,6
	rep movsb
	mov eax,eax  ;code alignment or mode conversion like 8bit to 16bit

	;cmpsd
	cld
L1:
	mov esi,offset str03
	mov edi,offset str04
	cmpsd
	ja L1
	mov eax,eax

	;scasb
	mov edi,offset str05
	mov al,'C'
	mov ecx,lengthof str05
	cld
	repne scasb
	dec edi
	mov eax,eax

	;stosb
	mov al,0FFh
	mov edi,offset str06
	mov ecx,100
	cld
	rep stosb
	mov eax,eax


	;Exit
	push 0
	call ExitProcess
	add esp,4

main ENDP
END main

;Transfer
;MOVSB  MOVSW  MOVSD  //byte  word  dword

;compare
;CMPSB  CMPSW  CMPSD  CMD

;scan
;SCASB  SCASW  SCASD

;store
;STOSB  STOSW  STOSD

;load
;LODSB  LODSW  LODSD
;mov al,[esi]
;inc esi

;REP  REPZ  REPE  REPNZ  REPNE