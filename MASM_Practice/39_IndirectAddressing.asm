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

;typedef
mybyte typedef ptr byte

.data 
var01 mybyte 2

arrNum01 DWORD 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16
arrNum02 byte 0,1,2,3,4,5
arrNum03 DWORD 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16


.code
main PROC
	;*arrNum01[i++]
	mov eax,offset arrNum01
	inc DWORD ptr [eax]
	mov eax,[eax]

	;Initial eax, ebx
	xor eax,eax
	xor ebx,ebx

	;Iterate through array
	mov eax,offset arrNum02
	mov bl,[eax]
	inc eax
	mov bl,[eax]
	inc eax
	mov bl,[eax]
	inc eax
	mov bl,[eax]
	inc eax
	mov bl,[eax]

	mov eax,offset arrNum02
	mov bl,[eax + 1]
	mov bl,[eax + 2]

	;esi: scale factor
	mov esi,4    ;DWORD == 4 * Byte == 8 * Word == 32 * Bit
	mov eax,arrNum03[0]
	mov eax,arrNum03[esi]
	mov eax,arrNum03[esi * 2]
	;mov eax,arrNum03[esi * 3]    ;can not be this, error addressing mode
	mov eax,arrNum03[esi * 2 + esi]
	mov eax,arrNum03[esi * 4 + esi]

	;Exit
	push 0
	call ExitProcess
	add esp,4

main ENDP
END main