#include <iostream>

int main()
{
	// Variable declare (C++11 standard)
	int nNumber1 = 5;
	int nNumber2 = { 10 };
	int nNumber3 = {};
	int nRet = { nNumber1 + nNumber2 + nNumber3 };

	// Base System
	// 0x	0	0b 
	// 0x4d2 == 1234 == 02322 == 0b010011010010

	// Singed	Unsinged	Long
	int uNumber4 = 5u;
	long LNumber5 = 5L;
	unsigned long long uLLNumber5 = 5ULL;

	// Data type transform
	float fNumber6 = { 50.212341 };
	int nNumber6 = static_cast<int>(fNumber6);

	// char    wchar_t    char16_t     char32_t
	char szStr1{ 'C' };
	wchar_t szStr2{ L'C' };
	char16_t szStr3{ u'C' };
	char32_t szStr4{ U'C' };

	// auto
	auto a = 5;	// int
	auto b = 'C';	// char
	auto c = 3.14159;	// float

	// Formatted output
	std::cout << uLLNumber5 << std::endl; 
	std::cout << std::hex << nRet << std::endl;
	std::cout << "end" << std::endl;
	return 0;
}