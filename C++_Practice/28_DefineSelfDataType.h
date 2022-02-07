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
	//Box(int a = 10, int b = 10, int c = 10);
	//Box(int a, int b, int c);
	//Box() :Box(5, 5, 5) { std::cout << "hello class!" << std::endl; };

	// Destructor
	~Box();

	int volume()
	{
		return this->length * this->width * this->height;
	}

	// Get 
	//int GetLength() { return length; }
	//int GetWidth() { return width; }
	//int GetHeight() { return height; }
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


	// Friend Function
	friend int testFriend(const Box& aBox);

	// Friend Class
	friend class TestFrend;

	// Static inline function(C++17)
	static inline int objectCount{ 0 };
};


// Friend Class Test
class TestFrend
{
public:
	TestFrend();
	~TestFrend();

private:

};