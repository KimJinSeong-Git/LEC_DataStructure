#pragma once
#include<stdio.h>
#include<stdlib.h>
#include <Windows.h>

#define m 12
#define p 12
#define Max_dir 8
#define Timestep 1000

#define OPEN 0
#define CLOSED 1
#define START 2
#define DST 3

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

void loadMaze(int maze[][p+2], char* fileRoot);
void printMaze(int maze[][p+2]);
void gotoxy(int x, int y);
void push(listPointer * top, ty_element item);
ty_element pop(listPointer * top);
void reverse(listPointer * ptr_top);
int path(int sy, int sx, int dy, int dx);
