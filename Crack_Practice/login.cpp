#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Code Generation -> Runtime: /MT
int main()
{
	char pwd[7] = { 'w','h','o','a','m','i' ,0 };
	printf("Please enter password:\n");
	char inputPwd[50] = { 0 };
	scanf("%s", &inputPwd);
	int nflag = 0;
	for (int i = 0; i < sizeof(pwd); i++)
	{
		if (pwd[i] == inputPwd[i])
		{
			nflag++;
		}
	}
	if (nflag > 6) 
	{
		printf("Login succeed!");
	}
	else 
	{
		printf("Login failed!");
	}

	system("pause");
	return 0;
}

// Crack Method
// 1.Modify jump
// 2.modify key value
// 3.Analyze the code
// 4.modify logical code