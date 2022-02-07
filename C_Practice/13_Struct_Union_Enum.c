#include "13_Struct_Union_Enum.h"

int main()
{
	// Struct
	struct NPCInfo NPC01 = { "NPC01", 100,100,12.3,166.74,0 };
	struct GamePlayerInfo player01 = { 0 };
	GPInfo * currentPlayer;	// Typedef 
	
	player01.PlayerNPCInfo.HP = 200;
	currentPlayer = &player01;

	printf("%d\t", player01.PlayerNPCInfo.HP);
	printf("%d\t", currentPlayer->PlayerNPCInfo.HP);
	printf("%d\n", (*currentPlayer).PlayerNPCInfo.HP);



	// Union
	/* Note: Union can be defined as a user-defined data type which is a collection 
	of different variables of different data types in the same memory location. 
	The union can also be defined as many members, but only one member can contain
	a value at a particular point in time.
	*/
	union Info myInfo;
	strcpy(myInfo.describe, "test info");
	myInfo.age = 65;	// &myInfo == &myInfo.describe == &myInfo.m == 0x010FFC14
	printf("%s\t%d\t%f\n", myInfo.describe, myInfo.age, myInfo.m);



	// Enum
	int myColor = beginner;
	switch (myColor)
	{
	case red:
		printf("red\n");
		break;
	case green:
		printf("green\n");
		break;
	case yellow:
		printf("yellow\n");
		break;
	case beginner:
		printf("beginner\n");
		break;
	default:
		printf("NULL\n");
		break;
	}

	return 0;
}
