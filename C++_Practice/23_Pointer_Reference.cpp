#include <iostream>


int main()
{
	int nNumArr1[10]{};
	int* p = nNumArr1;
	char* arrStr3{ nullptr }; // Pointer should be initialized
	arrStr3 = new char[5];
	memset(arrStr3, 0, 5);	// Initial
	strcpy_s(arrStr3, 4, "hhh");
	std::cout << arrStr3 << std::endl;
	if (arrStr3)
	{
		delete[] arrStr3;	// Pointer should be destroied
		arrStr3 = nullptr;	// Reinitial
	}


	// A pointer point to a const address
	int nNum7{ 10 };
	int& p2{ nNum7 };


	const char* arrStr1[]{ "Who am I?" };	// The rvalue is a const, so the lvalue type need also be const
	char arrStr2[]{ "Who am I?" };
	char* pArrStr2 = arrStr2;
	pArrStr2[3] = 'o';
	
	for (size_t i = 0; i < std::size(nNumArr1); i++)
	{
		nNumArr1[i] = i;
	}

	// *(p + 1)    address + (data type)    int == 32 bit == 4 Byte
	std::cout << *(p + 1) << std::endl;



	// Smart Pointer, automaticly delete itself
	// alloc memory in heap, stored in stack
	std::unique_ptr<int>pNum5{ new int{12345} };
	std::unique_ptr<int[]>pArrNum5{ new int[10] };
	std::unique_ptr<int>pNum6{ std::make_unique<int>(12345) };
	auto pNum7{ std::make_unique<int>(12345) };
	
	// equal to these:
	//int* pNum5{ nullptr };
	//pNum5 = new int;
	//*pNum5 = 12345;
	std::cout << *pNum5 << *pNum6 << *pNum7 << std::endl;

	for (size_t i = 0; i < sizeof(pArrNum5); i++)
	{
		pArrNum5[i] = i;
		std::cout << pArrNum5[i] << std::endl;
	}
	std::cout << std::hex << std::showbase << pArrNum5.get() << std::endl;
	int* nP = pArrNum5.release();
	pArrNum5.reset();

	std::cout << "endl" << std::endl;
	return 0;
}