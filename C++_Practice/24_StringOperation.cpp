#include <iostream>
#include <string>

int main()
{
	int nNum = 50;
	
	// String initial & operation
	std::string arrStr01{ "who am i" };
	const char* arrStr02 = arrStr01.c_str();
	//char* arrStr02 = arrStr01.data();  // C++ 17
	std::string arrStr03{ "who am i mam1111", 14 };
	std::string arrStr04{ arrStr01, 2, 5 };
	std::string arrStr05{ 10, 'a', 'b', 'c', 'd'};
	std::string arrStr06 = arrStr01 + arrStr04 + ' ' + "::" + std::to_string(nNum);
	std::string arrStr07 = arrStr01.substr(5, 3);
	arrStr05.insert(2, "who");
	arrStr05.replace(5, 2, "ddd");
	std::string arrStr08 = "666888";
	std::string arrStr09 = { "where am\\ i" };
	int nNum02 = { std::stoi(arrStr08) };
	int nNum03 = arrStr01.length();

	// char * = string
	// wchar_t = wstring
	// char16_t = u16string
	// char32_t = u32string
	std::wstring arrWStr{ L"who are you" };
	std::wcout << arrWStr << std::endl;

	if (arrStr01 == arrStr02)
	{
		std::cout << "==" << std::endl;
	}

	if (arrStr01.compare("who am i") == 0)
	{
		std::cout << "==" << std::endl;
	}

	std::cout << "find location here: " << arrStr01.find("am") << std::endl;
	std::cout << "find location here: " << arrStr03.rfind("am") << std::endl;
	std::cout << "find location here: " << arrStr03.find_first_of("m,a") << std::endl;


	std::cout << arrStr01 << std::endl;
	std::cout << arrStr02 << std::endl;
	std::cout << arrStr03 << std::endl;
	std::cout << arrStr04 << std::endl;
	std::cout << arrStr05 << std::endl;
	std::cout << arrStr06 << std::endl;
	std::cout << arrStr07 << std::endl;
	std::cout << arrStr08 << std::endl;
	std::cout << arrStr09 << std::endl;

	std::cout << "endl" << std::endl;
	return 0;
}