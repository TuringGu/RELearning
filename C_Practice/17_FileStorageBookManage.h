#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MaxBookNameLength 50
#define MaxInputBufferLength 1024
#define MaxOutputBufferLength 1024

enum UserChoice{flagExit, flagAppend, flagQuery, flagModify, flagDelete};

void AppendBook(char *DatabaseFile, char *BookName, int BookNumber, float BookPrice);
void QueryBook(char *DatabaseFile, char *BookName);
void ModifyNode(char* DatabaseFile, char* TempFile, char *BookName, char *NewBookName, int BookNumber,float BookPrice);
void DeleteNode(char* DatabaseFile, char* TempFile, char* BookName);