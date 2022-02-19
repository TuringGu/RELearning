#include <stdio.h>

// Code generation:
// need change to multi-thread debug(MTD) mode
int main()
{
	int var01 = 10;
	_asm {
		mov eax,5
		add eax,6
	}
	_asm mov ebx,eax
	_asm mov ecx,ebx
	return 0;
}