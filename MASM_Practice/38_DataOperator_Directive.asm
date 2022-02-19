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
num01 dword 5
var01 db ?
var02 byte ?
var03 word ?
var04 dword ?
arrNum01 DWORD 0,1,2,3,4,5


.code
main PROC
	;offset
	mov eax,offset var01

	mov eax,offset arrNum01 + 4
	mov eax,[eax]	;*(arrNum01+4)

	;ptr
	mov ax,word ptr num01

	;type
	mov eax,type var01
	mov eax,type var02
	mov eax,type var03
	mov eax,type var04

	;lengthof
	mov eax,offset lengthof arrNum01

	;sizeof
	mov eax,sizeof arrNum01


	;Exit
	push 0
	call ExitProcess
	add esp,4

main ENDP
END main