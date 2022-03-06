#include <stdio.h>
#include <windows.h>

DWORD GetHash(char * fun_name)
{
    DWORD digest = 0;
    while(*fun_name)
    {
        digest = ((digest<<25)|(digest>>7));
        digest += *fun_name;
        fun_name++;
    }
    return digest;
}

void main()
{   
    DWORD hash1, hash2, hash3;
    hash1 = GetHash("MessageBoxA"); // user32.dll
    hash2 = GetHash("ExitProcess"); // kernel32.dll
    hash3 = GetHash("LoadLibraryA");// kernel32.dll
    printf("hash1: %.8x\n", hash1);
    printf("hash2: %.8x\n", hash2);
    printf("hash3: %.8x\n", hash3);
}