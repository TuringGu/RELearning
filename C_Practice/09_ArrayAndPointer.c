#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

#define MAX 10

void add(int *a, int *b)
{
	int temp = *a + *b;
	*a = temp;
}

void add1Arr(int *e)
{
	for (size_t i = 0; i < 5; i++)
	{
		e[i] = e[i] + 1;
	}
}


int main()
{
	// Array
	// a set of variables of the same type
	const int Number[MAX] = { 0,1,2,3,4,5,6,7,8,9 };
	for (size_t i = 0; i < 10; i++)
	{
		printf("%d\n", Number[i]);
	}
	// 1-dimension array
	int Number1[5] = { 0 };
	// 2-dimension array
	int Number2[3][5] = { {0,1,2,3,4},{ 0,1,2,3,4 },{ 0,1,2,3,4 } };
	for (size_t i = 0; i < 5; i++)
	{
		Number2[0][i] = i;
	}


	// Pointer
	// "&": address operator
	// "*": indirection operator
	int Number3 = 0;
	int *pNum = &Number3;
	*pNum = 5;	// &Number3 = address1, pNum = address1, *pNum = 5, address1 = 5
	Number3 = 6;
	printf("The value and address of Variable Number3 is: %d, %x\n", Number3, &Number3);
	// Transfer parameters with pointer
	int x = 5, y = 6;
	add(&x, &y);
	printf("After the add function, the value of x is: %d\n", x);


	// Array with Pointer
	// address2 = Number4 = pNum2
	// pointer address + sizeof(variable type);
	int Number4[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int *pNum2 = Number4;
	for (size_t i = 0; i < 10; i++)
	{
		printf("%d\n", pNum2[i]);
	}

	// Transfer parameters of array by using pointer in function
	int Number5[5] = { 4,3,2,1,0 };
	add1Arr(Number5);	// Every element add 1
	for (size_t i = 0; i < 5; i++)
	{
		printf("%d ", Number5[i]);
	}

	return 0;
}