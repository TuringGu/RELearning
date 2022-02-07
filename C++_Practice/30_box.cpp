#include "30_box.h"

Box::Box()
{
}

Box::Box(int a, int b, int c)
{
	length = a;
	width = b;
	height = c;
}

Box::~Box()
{
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


// Operator Overloading
bool Box::operator<(Box& aBox)
{
	std::cout << "hello operator" << std::endl;
	return this->volume() < aBox.volume();
}

std::ostream& operator<<(std::ostream& stream, Box& aBox)
{
	stream << "Box("<< aBox.GetLength() << ',' << aBox.GetWidth() << ',' <<
		aBox.GetHeight() << ')';
	return stream;
}

Box Box::operator~()
{
	return Box(height, width, length);
}

void Box::showVolume()
{
	std::cout << volume() << std::endl;
}
