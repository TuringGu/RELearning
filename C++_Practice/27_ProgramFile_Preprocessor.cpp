#include <iostream>
#include <assert.h>
#define PI 3.1415926
#define MAX(A, B) A >= B ? A : B
#undef PI
#define ABC 5

namespace MyNameTestOfMine
{
	const float myPI{ 3.14159 };
	int add(int a, int b);
	int add(int a, int b)
	{
		return a + b;
	}
}

namespace MyName = MyNameTestOfMine;

using namespace MyName;
using namespace std;

// Transfer Unit
// Preprocessor source code
// Namespace
int main()
{
	
	cout << myPI << endl;
	cout << add(1, 2) << endl;

#if  ABC == 5
	std::cout << 123 << std::endl;
#endif //  ABC == 5

	// Program assertion
	assert(true);
	//static_assert(true);
	//assert(1 > 2);	//break, calling abort()

	std::cout << "endl" << std::endl;
	return 0;
}

