#pragma once
#include "30_box.h"

class cox: public virtual Box
{
public:
	cox();
	cox(int a, int b, int c);
	~cox();
	int test{ 10 };

	// Inheritance
	int volume() override final;

private:

};
