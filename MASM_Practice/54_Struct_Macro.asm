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

;struct
myStruct struct
	sd01 dword ?
	sd02 dword ?
myStruct ends

;macro
myMacro MACRO char
	mov eax,char
ENDM

.data 
myStruct01 myStruct <>

.code
main PROC
	mov myStruct01.sd01,1
	mov eax,myStruct01.sd01
	myMacro 10

	mov eax,eax
main ENDP
END main