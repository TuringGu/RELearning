#include <iostream>

template <typename T> T add(T a, T b);

int main()
{
	std::cout << add(1, 2) << "\n" << add(1.1, 2.2) << std::endl;
	std::cout << add(1, 2) << "\n" << add<float>(1.1, 2.2) << std::endl;
	std::cout << add(1, 2) << "\n" << add<int>(1.1, 2.2) << std::endl;

	std::cout << "endl" << std::endl;
	return 0;
}

template<typename T>
T add(T a, T b)
{
	return a + b;
}