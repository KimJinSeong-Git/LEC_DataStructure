#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �л� ��� ����
typedef struct Listdata {
	char name[30];
	int id;
} listData;

// ����Ʈ ��� ����
typedef struct ListNode {
	listData data;
	struct ListNode* link;
} listNode;

// ����Ʈ ��� ����
typedef struct LinkedList {
	listNode* head;
	int length;
} linkedList;

// ---------- Prototype ----------
void readFile(linkedList* L, char* fileRoot);
linkedList* initList();
int getLength(linkedList* L);

void insertLast(linkedList* L, listData item);
int insert(linkedList* L, listNode* pre, listData item);
int delete(linkedList* L, int x);

listNode* search(linkedList* L, int x);
void printList(linkedList* L);
void reverse(linkedList* L);