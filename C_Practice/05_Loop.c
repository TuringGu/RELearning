#include <stdio.h>
#include <string.h>

int main()
{
	// 1.Loop counter initial value
	// 2.Judge whether it conforms to the expression
	// 3.Execute statement
	// 4.Loop counter value changed
	// ...
	for (int i = 5; i >= 1; i--) {
		for (int j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");
	}

	system("pause");
	return 0;
}