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
num01 dd 5
num02 dd 7
num03 dw 20
num04 dw -10
num05 SWORD -10


.code
main PROC
	mov eax,num01
	add eax,num02

	mov cx,num03
	mov eax,0FFFFFFFFh
	mov ax,cx

	movzx eax,cx

	mov dx,num05
	movsx eax,dx

	lahf
	movzx eax,ah

	xchg eax,ecx

	;Exit
	push 0
	call ExitProcess
	add esp,4

main ENDP
END main

;Type of operand
;Immediate value
;Register operand: eax ebx
;Memory operand

;Register
;reg8 reg16 reg32
;Segment register

;Immediate value
;imm8 imm16 imm64

;Memory
;mem8 mem16 mem32

;Destination operand
;Source operand
;int a = 15
;mov a,15

;mov reg,reg
;mov mem,reg
;mov reg,mem
;mov mem,imm
;mov reg,imm
;Can not be: mov mem,mem

;The way to mov reg16 to reg32
;mov eax,0FFFFFFFFh
;mov ax,cx
;
;movzx eax,cx        ;cx=10101010  eax=0000000010101010  
;
;movsx eax,cx        
;cx=10101010  eax=1111111110101010  
;cx=00101010  eax=0000000000101010  


;LAHF: read from flag register
;lahf
;mov flag,ah

;SAHF: write to flag register
;mov ah,flag
;sahf

;XCHG: exchange value
;xchg reg,reg
;xchg reg,mem
;xchg mem,reg