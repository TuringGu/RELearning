#include "30_box.h"
#include "30_cox.h"


int main()
{
	Box MyBox01(5, 6, 7);
	cox MyCox01(5, 6, 7);
	MyBox01.showVolume();
	MyCox01.showVolume();

	std::cout << "endl" << std::endl;
	return 0;
}