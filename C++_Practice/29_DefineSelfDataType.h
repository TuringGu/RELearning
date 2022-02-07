#pragma once
#include <iostream>


class Box
{
private:
	int length{ 1 };
	int width{ 1 };
	int height{ 1 };

public:
	// Constructor
	Box();
	Box(int a, int b, int c);

	// Destructor
	~Box();

	// Calculate the volume
	int volume()
	{
		return this->length * this->width * this->height;
	}

	// Get 
	int GetLength();
	int GetWidth();
	int GetHeight();

	// Set
	int SetLength(int newLength);
	int SetWidth(int newWidth);
	int SetHeight(int newHeight);

	// Set by pointer
	Box* SetBoxLength(int newLength);
	Box* SetBoxWidth(int newWidth);
	Box* SetBoxHeight(int newHeight);

	// Operator overloading
	bool operator < (Box& aBox);
	Box operator~();
	
};

// Operator overloading
std::ostream& operator<<(std::ostream& stream, Box& aBox);