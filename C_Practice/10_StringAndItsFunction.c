#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

int main()
{
	// Method of array's declare
	char szStr0[50] = "my name is xxx";
	char szStr1[50] = { 'm', 'y', ' ', 'n', 'a', 'm', 'e', ' ', 'i', 's', ' ', 'x', 'x', 'x', '\0' };
	char szStr2[] = "my name is xxx";
	char *szStr3 = "my name is xxx";
	char szStr4[50];
	gets(szStr4);
	char * szArrStr[3] = { "666", "asdfqwer", "12341234" };

	// gets() & puts()
	puts(szStr0);
	puts(szStr1);
	puts(szStr2);
	puts(szStr3);
	puts(szStr4);
	for (size_t i = 0; i < 3; i++)
	{
		puts(szArrStr[i]);
	}


	// fgets() & fputs()
	char szStr5[50];
	fgets(szStr5, 50, stdin);
	fputs(szStr5, stdout);

	// strlen() strcat() strncat() strcpy() strncpy() sprintf()
	char szStr6[50] = "whoami";
	char szStr7[50] = " Hello";
	char szStr8[10] = " ??????";
	char szStr9[50] = { 0 }, szStr10[50] = { 0 }, szStr11[50] = { 0 };
	int len = strlen(szStr6);
	strcat(szStr6, szStr7);
	strncat(szStr7, szStr8, 3);
	strcpy(szStr9, szStr8);
	strncpy(szStr10, szStr8, 3);
	sprintf(szStr11, "%s666%s", szStr6, szStr7);

	// strcmp() strncmp()
	if ((strcmp(szStr7, szStr8) != 0) && (strncmp(szStr7, szStr8, 1) != 0))
	{
		printf("!=");
	}
	else
	{
		printf("==");
	}

	return 0;
}
