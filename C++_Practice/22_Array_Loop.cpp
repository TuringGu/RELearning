#include <iostream>
#include <array>
#include <vector>

int main()
{
	// Declare array
	int nNumberArr1[200]{ 0,1,2,3,4,5,6,7,8,9 };
	int nNumberArr2[]{ 0,1,2,3,4 };
	int nSizeOfArr2 = std::size(nNumberArr2);
	char szStr3[5]{ 'a', 'b', 'c', 'd', 'e' };
	char szStr4[6]{ 'a', 'b', 'c', 'd', 'e', '\0' };
	char szStr5[6]{ "abcde" };
	std::cout << szStr5 << std::endl;

	// Two-dimension array
	int nNumberArr5[2][3]{};
	std::array<int, 6>nNumberArr6{ 0,1,2 };
	std::array<int, 6>nNumberArr7;
	nNumberArr7.fill(10);
	nNumberArr7.size();
	if (nNumberArr6 == nNumberArr7)
	{
		std::cout << "==" << std::endl;
	}
	else 
	{
		std::cout << "!=" << std::endl;
	}

	// vector
	std::vector<int>nNumberArr8;
	std::vector<int>nNumberArr9(20, 99L);
	std::vector<int>nNumberArr10{ 0,1,2,3,4 };
	nNumberArr8.push_back(5);
	nNumberArr8.push_back(10);
	nNumberArr8.pop_back();
	nNumberArr8.clear();
	nNumberArr10.at(3);

	// Loop
	// C++17: for    while    do while
	int nNumberArr3[100]{};
	int nSizeOfArr3 = std::size(nNumberArr3);

	for (int i = 0; i < nSizeOfArr3; i++)
	{
		if (i == 96)
		{
			nNumberArr3[i] = 666;
			continue;
		}
		if (i == 98)
		{
			break;
		}
		nNumberArr3[i] = i;
	}

	//for (auto x : nNumberArr3)
	//{
	//	std::cout << x << std::endl;
	//}
	for (auto x : {95,96,97,98,99})
	{
		std::cout << nNumberArr3[x] << std::endl;
	}

	std::cout << "endl" << std::endl;
	return 0;
}