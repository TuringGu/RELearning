#include <stdio.h>
#include <string.h>

int main()
{
	// In the division of C program, if the type is int, the tailer will be cut
	// if the type is float, the tailer will be retained
	printf("%d\n", 5 / 2);
	printf("%d\n", 5.0 / 2);
	printf("%f\n", 5 / 2);
	printf("%f\n", 5.0 / 2);

	system("pause");
	return 0;
}