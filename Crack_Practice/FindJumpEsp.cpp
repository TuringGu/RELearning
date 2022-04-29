#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

#define DLL_NAME "user32.dll"

int main()
{
	HINSTANCE hDllHandle = LoadLibrary(DLL_NAME);
	if (!hDllHandle)
	{
		exit(0);
	}

	BYTE* ptr;
	ptr = (BYTE*)hDllHandle;
	BOOL flag = false;
	int count = 0;
	for (int i = 0; !flag; i++)
	{
		// jump esp
		if (ptr[i] == 0xFF && ptr[i + 1] == 0xE4)
		{
			int address = (int)ptr + i;
			printf("opcode address:0x%x\n", address);
			count++;
			if (count >= 50) 
			{
				count = 0;
				system("pause");
			}
		}
	}
	return 0;
}