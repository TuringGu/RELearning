#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum UserChoice{flagExit, flagAppend, flagQuery, flagModify, flagDelete};

typedef struct Node
{
	char BookName[50];
	int BookNumber;
	float BookPrice;
	struct Node *next;
}Node;

Node *AppendNode(Node * head, char *BookName, int BookNumber, float BookPrice);
Node *QueryNode(Node * head, char *BookName);
void ModifyNode(Node * head, char *BookName, char *NewBookName ,float BookPrice);
Node *DeleteNode(Node * head, char *BookName);