#pragma once
#include<stdio.h>
#include<stdlib.h>
#include <Windows.h>

#define m 12
#define p 12
#define Max_dir 8
#define Timestep 1000

typedef struct Aoff {
	short int vert;
	short int horiz;
} offsets;

typedef struct St_element {
	short int row;
	short int col;
	short int dir;
} ty_element;

typedef struct ListNode* listPointer;
typedef struct ListNode {
	ty_element data;
	listPointer link;
} listNode;



void loadMaze(int* maze, char* fileRoot);