#include <stdio.h>

int main(){
	// the int, theory occupy 8 bit, -128 ~ 127
	// ASCII code, 0 ~ 127
	// Unicode, 16 bit or 32 bit
	// char name1 = 'A';
	// char name2 = 65;
	char name3;
	scanf("%c", &name3);
	// scanf_s scanf_s("%d", %Num, 10);
	//printf("%c", name2);

	// False declare method:
	// char name2 = A;
	// char name2 = "A";

	// \n \r 
	// \a  alert

	// float 32 bit
	// double 64 bit
	float num = 1.1;
	double num1 = 12E-5;
	printf("%f, %f", num, num1);

	// C99 standard
	// 0: false, 1: true
	_Bool flag = 0;

	// Basic type
	// int long short unsigned, char, float, double, signed, _Bool, _Complex, _Imaginary
	// include a header file, inttype.h   uint64_t


	int num3 = 100;
	printf("8 decimal: %o, 10 decimal: %d, hexdecimal: %x", num3, num3, num3);

	// Pause
	//getchar();
	system("pause");

	return 0;
}

// int type occupy 32 bit
// -2^31 ~ 2^31-1
// -2147483648 ~ 2147483647
// INM PC -2^15 ~ 2^15-1
// -32768 ~ -32767

// int 32 bit
// short int 16 bit, mean not longer than int type
// %hd
// long int 32 bit, mean not shorter than int type
// %ld
// %lx %lo
// long long int 64bit
// %lld %llx %%llu

// unsigned
// unsigned int

