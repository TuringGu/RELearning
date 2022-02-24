#include <stdio.h>
#include <stdlib.h>

// Code Generation -> Runtime: /MT
int main()
{
	int nNum = 0;
	scanf("%d", &nNum);

	if (nNum == 0)
	{
		printf("True!\n");
	}
	else
	{
		printf("false!\n");
	}
	system("pause");
	return 0;
}