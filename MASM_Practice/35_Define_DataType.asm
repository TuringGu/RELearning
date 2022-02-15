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
; == char *szStr="who am I?" in C program
szStr db "who am I?",0
num dword 5
; == arrNum[20] = {0} in C program
arrNum dword 20 dup(0)
; arrNum dword 20 dup(?)  not initialized array

.code
main PROC
	mov [arrNum],12345678h
	mov [arrNum + 4],11111111h
	mov [arrNum + 8],22222222h
	push offset szStr
	call crt_printf
	add esp,4
	
	;Exit
	push 0
	call ExitProcess
	add esp,4

main ENDP
END main

;Intrinsic Data Types
;Integer
;BYTE    8bit    unsigned
;SBYTE   8bit    signed
;WORD   16bit    unsigned
;SWORD  16bit    signed
;DWORD  32bit    unsigned
;SDWORD 32bit    signed
;FWORD  48bit    Far pointer of protection mode
;QWORD  64bit    Integer
;TBYTE  80bit    Integer
;
;Real Number
;REAL4  32bit    short 
;REAL8  64bit    long
;REAL10 80bit    extend

;Directive
;db     8bit     Integer
;dw    16bit     Integer
;dd    32bit     Integer or Real number
;dq    64bit     Integer or Real number
;dt    80bit     Integer

;There is smail end
;78 56 34 12