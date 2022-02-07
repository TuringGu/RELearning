#include "29_DefineSelfDataType.h"


int main()
{
	Box MyBox01(5, 6, 7);
	Box MyBox02(20, 3, 4);
	
	if (MyBox01 < MyBox02)
	{
		std::cout << "MyBox01 < MyBox02" << std::endl;
	}
	else
	{
		std::cout << "MyBox01 > MyBox02" << std::endl;
	}

	std::cout << MyBox01 << std::endl;

	MyBox02 = ~MyBox01;	// Transposition
	std::cout << MyBox02 << std::endl;

	std::cout << "endl" << std::endl;
	return 0;
}