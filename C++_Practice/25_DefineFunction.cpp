#include <iostream>


// Function Declaration
void my_add(int* a, int b);	// Arguments: a, b
void my_add(int& a, int b = 0);
float my_add(float* a, int b);
void my_add(int a[], int b, int arrLength);	
void selfAdd(int* a, int nCycleTimes);

int main()
{
	int nRet{ 0 };
	int nX = 1;
	int& nC{ nRet };
	int arrNX[10]{ 0 };
	float fX{ 3.3 };
	int nY{ 3 };

	//int x = sizeof(arrNX);
	//int y = std::size(arrNX);

	my_add(&nX, 2);	// Parameters: 1, 2
	my_add(nC, 8);
	my_add(arrNX, 5, std::size(arrNX));
	my_add(arrNX, -1, std::size(arrNX));
	my_add(arrNX, 6, std::size(arrNX));
	fX = my_add(&fX, 2);
	selfAdd(&nY, 10);

	std::cout << nX << std::endl;

	std::cout << "endl" << std::endl;
	return 0;
}

// Function Definition
void my_add(int* a, int b)
{
	*a += b;
}


// Function Overload
// function parameters number different || at least one couple of paramater type different
void my_add(int a[], int b, int arrLength)
{
	static int nCallCount{ 0 };	// Static: only initial once
	for (int i = 0; i < arrLength; i++)
	{
		a[i] += b;
	}
	nCallCount++;
	std::cout << "Call func num: " << nCallCount << std::endl;
}


// Function Overload
// inline: for program optimization, compiler choose the short function to replace
// in the calling palce, for reduce function calling
inline void my_add(int& a, int b)
{
	a += b;
}

float my_add(float* a, int b)
{
	return *a + b;
}

// Function recursive
void selfAdd(int* a, int nCycleTimes)
{
	if (nCycleTimes > 0)
	{
		*a += *a;
		selfAdd(a, --nCycleTimes);
	}	
}