#include "28_DefineSelfDataType.h"


int main()
{
	//Box MyBox01(1, 2, 3);
	//Box MyBox02{};
	Box MyBox03;
	Box MyBox04{ MyBox03 };
	Box MyBox05[10];
	Box MyBox06[10];

	// Set
	MyBox03.SetHeight(6);
	MyBox03.SetLength(7);
	MyBox03.SetWidth(8);

	// Set by pointer
	MyBox04.SetBoxHeight(3)->SetBoxLength(4)->SetBoxWidth(5);

	//std::cout << MyBox01.volume() << std::endl;
	//std::cout << MyBox02.volume() << std::endl;
	std::cout << MyBox03.volume() << std::endl;
	std::cout << MyBox04.volume() << std::endl;
	std::cout << MyBox03.GetHeight() << "\t" << MyBox03.GetLength() 
		<< "\t" << MyBox03.GetWidth() << std::endl;

	std::cout << MyBox05[0].volume() << std::endl;
	std::cout << MyBox05[1].volume() << std::endl;
	std::cout << MyBox05[2].volume() << std::endl;
	std::cout << MyBox05[3].volume() << std::endl;

	// Using friend function to access private 
	testFriend(MyBox03);

	// static inline & destructor
	std::cout << MyBox06[0].objectCount << std::endl;
	std::cout << MyBox06[8].objectCount << std::endl;

	std::cout << "endl" << std::endl;
	return 0;
}