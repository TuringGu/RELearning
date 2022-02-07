#pragma once
#include <iostream>


class Box
{
protected:
	int length{ 1 };
	int width{ 1 };
	int height{ 1 };

public:
	// Constructor
	Box();
	Box(int a, int b, int c);

	// Destructor
	virtual ~Box();

	// Calculate the volume
	// The virtual function
	int virtual volume()
	{
		return this->length * this->width * this->height;
	}

	// Pure virtual function
	//virtual void vol() = 0;

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

	// Polymorphism
	void showVolume();
};

// Operator overloading
std::ostream& operator<<(std::ostream& stream, Box& aBox);