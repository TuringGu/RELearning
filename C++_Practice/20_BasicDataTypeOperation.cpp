#include <iostream>

// Not recommend in C++
// typedef unsinged int uInit32	

using uInt32 = unsigned int;
uInt32 a = 0;	// Global variable

int main()
{
	// Bit Operation
	// & And
	// | Or
	// ~ NOT(bit)
	// ! NOT(Logical)
	// ^ XOR
	// <<  >>

	// Symmetric encryption
	int nNumber1 = 50;
	int nNumber2 = 90;
	int nEncrypt1 = nNumber1 ^ nNumber2;
	int nDecrypt1 = nEncrypt1 ^ nNumber2;

	uInt32 nNum{ 0 };

	std::cout << "end" << std::endl;
	return 0;
}