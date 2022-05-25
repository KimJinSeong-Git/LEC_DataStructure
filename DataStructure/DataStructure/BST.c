#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 6

typedef int itemStock;
typedef struct {
	char itemCode[MAX_CODE_LENGTH];
	itemStock stock;
} item;

typedef struct treeNode {
	item key;
	struct treeNode* left;
	struct treeNode* right;
} treeNode;

void displayBST(treeNode* bt);
void searchBST(treeNode* bt, item data);
void insertBST(treeNode* bt, item data);

int main() {
	treeNode* p = NULL;
	item t;

	strcpy(t.itemCode, "12345");
	t.stock = 10;
	insertBST(p, t);

	displayBST(p);
	return 0;
}

void displayBST(treeNode* bt) {
	treeNode* p = bt;
	printf("[system] 전체 재고 출력\n");
	if (p != NULL) {
		displayBST(p->left);
		printf("- 관리번호: %s, 재고: %d\n", p->key.itemCode, p->key.stock);
		displayBST(p->right);
	}
}

void insertBST(treeNode* bt, item data) {
	treeNode* p = bt;
	treeNode* parent = NULL;

	while (p != NULL) {
		if (data.itemCode == p->key.itemCode) {
			p->key.stock += data.stock;
			printf("[system] 존재하는 상품코드입니다.\n상품코드 %s의 재고는 %d개 입니다.\n", p->key.itemCode, p->key.stock);
			return;
		}
		parent = p;
		if (data.itemCode[0] < p->key.itemCode[0])
			p = p->left;
		else
			p = p->right;
	}

	treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
	newNode->key = data;
	newNode->left = NULL;
	newNode->right = NULL;

	if (bt == NULL)
		bt = newNode;
	else if (data.itemCode[0] < parent->key.itemCode[0])
		parent->left = newNode;
	else
		parent->right = newNode;
}