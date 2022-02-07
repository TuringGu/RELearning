#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <float.h>

#define PI 3.1415926

int main() {
	// String, the array of char
	// A B C D \0
	// four char and one 00, occupy five memory unit 
	char name1[128] = { 'A', 'B', 'C', 'D', 0 };
	char name2[128] = "ABCD";
	char name3[] = "ABCD";
	char name4[8];

	// As for parameter of scanf(),  string variable do not need to add '&'
	//scanf_s("%s", name4, 8);
	//printf("%s", name4);

	// sizeof(): return the number of occupied memory unit
	// strlen(): return the number of valid char, get NULL to stop , NULL == 00
	sizeof(name1);
	strlen(name1);
	sizeof(name3);
	strlen(name3);	// belong to <string.h>


	// const value can't be changed by program
	// System defined const value in files like <limits.h>, <float.h>
	const int age = 30;


	// printf()
	// parameter 1: formatted string
	// parameter 2: variables
	char name5[] = "scott";
	printf("My name is %s\n", name5);
	long int age2 = 50;
	printf("%-10d\n", age2);
	printf("%10d\n", age2);

	// scanf()
	// parameter 1: formatted string
	// parameter 2: &variables(string variables do not need add '&')
	// Separators determine your input separator
	int a, b, c, d;
	scanf("%d %d", &a, &b);
	scanf("%d,%d", &c, &d);


	system("pause");
	return 0;
}