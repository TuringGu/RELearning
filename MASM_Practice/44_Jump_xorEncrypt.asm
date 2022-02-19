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
key db 10
source byte "who am i?",0
sourcesize = ($ - source) - 1

.code
;XOR Encrypt & Decrypt
;esi: array address
;ecx: array length
xor_encrypt proc uses esi ecx
	mov eax,0  ;Initial
jnz01:
	mov al,[esi]
	xor al,key
	mov [esi],al
	inc esi    ;next element
	dec ecx
	cmp ecx,0
	jnz jnz01

	ret
xor_encrypt endp

; a xor b xor b == a
main PROC
	;Encrypt
	mov esi,offset source
	mov ecx,sourcesize
	push esi
	push ecx
	call xor_encrypt

	;Decrypt
	mov esi,offset source
	mov ecx,sourcesize
	push esi
	push ecx
	call xor_encrypt

	;Exit
	push 0
	call ExitProcess
	add esp,4

main ENDP
END main
