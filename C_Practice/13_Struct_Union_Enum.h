#pragma once
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

typedef int myDefInt;

struct NPCInfo
{
	char NPCName[50];
	int HP, MP;
	float x, y, z;	// Location
};

typedef struct GamePlayerInfo
{
	char PlayerName[50];
	int level;
	struct NPCInfo PlayerNPCInfo;
}GPInfo;

union Info
{
	char describe[100];
	int age;
	float m;
};

enum Color{red, green, yellow};

enum Title
{
	beginner = 10,
	veteran = 100
};