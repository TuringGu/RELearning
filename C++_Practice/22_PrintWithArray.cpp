#include <iostream>
#include <array>

const char ASTERISK = '*';
const char BLANK = ' ';
const char PRINTSYMBOL = ASTERISK;
const int ARRMAXLENGTH = 21;	// Should be singular


int main()
{
	//std::array<char, ARRMAXLENGTH>szSymbolArr{};
	char szSymbolArr[ARRMAXLENGTH + 1] = {};


	// Print 1
	for (int i = 0; i < sizeof(szSymbolArr) - 1; i++)
	{
		szSymbolArr[i] = PRINTSYMBOL;
		std::cout << szSymbolArr << std::endl;
	}
	std::cout << "\n\n" << std::endl;


	// Print 2
	for (int i = sizeof(szSymbolArr) - 2; i >= 0; i--)
	{
		std::cout << szSymbolArr << std::endl;
		szSymbolArr[i] = BLANK;
	}
	std::cout << "\n\n" << std::endl;


	// Print 3 (mathematic realization)
	// varaible: n = arrayLength   lineNumber = n
	// 
	// line: i[1,n]
	// 
	// symbol number: 
	// i[1, (n+1)/2],  2i-1
	// i[(n+3)/2], n], 2(n-i)+1
	//
	// Blank number(do not need calculate):
	// i[1, (n+1)/2] , n-2i+1
	// i[(n+3)/2], n], 2(i-n)+1
	//
	// Output start locator:
	// i[1, (n+1)/2], (n+3)/2-i
	// i[(n+3)/2], n], (1-n)/2+i
	//
	// here: n = (sizeof(szSymbolArr) - 1)


	// print3
	int nMiddleArr = sizeof(szSymbolArr) / 2;
	for (int i = 0, j = 0; i < sizeof(szSymbolArr) - 1; i++)
	{
		if (i < nMiddleArr)
		{
			szSymbolArr[nMiddleArr - 1 - i] = PRINTSYMBOL;
			szSymbolArr[nMiddleArr - 1 + i] = PRINTSYMBOL;
		}
		else
		{
			szSymbolArr[j] = BLANK;
			szSymbolArr[2 * nMiddleArr - 2 - j] = BLANK;
			j++;
		}
		std::cout << szSymbolArr << std::endl;
	}
	std::cout << "\n\n" << std::endl;

	std::cout << "endl" << std::endl;
	return 0;
}