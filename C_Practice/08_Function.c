#include "08_Function.h"  

// Function: packet some function to reuse
int main()
{
	// "0" is a real parameter
	printNumber(0);

	return 0;
}

// "a" is a formal paramter
int printNumber(int a)
{
	printf("%d\n", a);
	if (a <= 10)
	{
		// Recursive 
		printNumber(a + 1);
	}
	return 0;
}
