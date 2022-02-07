#include "30_cox.h"

cox::cox()
{
}

cox::cox(int a, int b, int c)
{
	length = a;
	width = b;
	height = c;
}

cox::~cox()
{
}

// Inheritance
int cox::volume()
{
	return 0.85 * (length * width * height);
}
