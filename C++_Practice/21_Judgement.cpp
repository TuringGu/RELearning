#include <iostream>


int main()
{
	int flag{ 0 };

	//if else
	int a = 10, b = 20;
	int c = a > b ? 10 : 20;

	// switch
	std::cout << "enter a number: " << std::endl;
	std::cin >> flag;
	switch (flag)
	{
	case 1:
		std::cout << "you entered " << "one" << std::endl;
		break;
	case 2:
		std::cout << "you entered " << "two" << std::endl;
		break;
	case 3:
		std::cout << "you entered " << "three" << std::endl;
		break;
	default:
		std::cout << "you did not enter 1,2,3 " << std::endl;
		break;
	}
	
	std::cout << "End" << std::endl;
	return 0;
}