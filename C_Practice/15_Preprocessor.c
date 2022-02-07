#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <math.h>

#define MYDEF1(X) printf("This is my define: %d\n", X)
#define MYDEF2(Y) Y * Y
#define MYDEF3
#define MYDEF4 2

int main()
{
	MYDEF1(5);
	printf("%d\n", MYDEF2(3));

	int a = fabs(-15);
	float b = sqrt(15);

// #ifdef #else #endif
#ifdef MYDEF3
	printf("MYDEF3 defined\n");
#else
	printf("MYDEF3 not defined\n");
#endif // MYDEF3

// #if #elif
#if MYDEF4 == 1
	printf("MYDEF4 is 1");
#elif MYDEF4 == 2
	printf("MYDEF4 is 2");
#endif

	return 0;
}
