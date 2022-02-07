#include "28_DefineSelfDataType.h"

Box::Box()
{
	objectCount++;
}

//Box::Box(int a, int b, int c)
//{
//	length = a;
//	width = b;
//	height = c;
//	objectCount++;
//}

Box::~Box()
{
	objectCount--;
	std::cout << objectCount << "end" << std::endl;
}

// Get
int Box::GetHeight()
{
	return height;
}

int Box::GetLength()
{
	return length;
}


int Box::GetWidth()
{
	return width;
}

// Set
int Box::SetLength(int newLength)
{
	this->length = newLength;
	return 0;
}

int Box::SetWidth(int newWidth)
{
	this->width = newWidth;
	return 0;
}

int Box::SetHeight(int newHeight)
{
	this->height = newHeight;
	return 0;
}

// Set by pointer
Box* Box::SetBoxLength(int newLength)
{
	this->length = newLength;
	return this;
}

Box* Box::SetBoxWidth(int newWidth)
{
	this->width = newWidth;
	return this;
}

Box* Box::SetBoxHeight(int newHeight)
{
	this->height = newHeight;
	return this;
}

// Friend function
int testFriend(const Box& aBox)
{
	std::cout << aBox.height << std::endl;
	return 0;
}
