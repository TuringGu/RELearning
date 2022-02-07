#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

int main()
{
	// Static storage duration
	// Dynamic storage duration

	// register
	// outer connect extern storage class
	// Inner connect static storage class
	// Empty connect static storage class

	// malloc() free()
	char szStr[] = "who am i";
	char * szStr1;
	int length = (strlen(szStr) + 1);
	szStr1 = (char *)malloc(length * sizeof(char));
	memset(szStr1, 0, length);
	strcpy(szStr1, szStr);
	puts(szStr1);
	free(szStr1);

	return 0;
}
