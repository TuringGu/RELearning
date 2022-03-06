#include <stdio.h>
#include <windows.h>

#define DLL_NAME = "user.32.dll"

int main()
{
	HINSTANCE hDllHandle = LoadLibrary(DLL_NAME);
	if(!hDllHandle)
	{
		exit(0);
	}

	BYTE * ptr;
	ptr = (BYTE*)hDllHandle;
	BOOL flag = false;
	for(int i = 0; !flag; i++)
	{
		if(ptr[i] == 0xFF && ptr[i + 1] == 0xE4)
		{
			int address = (int)ptr + i;
			printf("opcode address:0x%x",address);
		}
	}
	return 0;
}