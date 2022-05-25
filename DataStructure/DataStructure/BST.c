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

typedef struct BST {
	treeNode* head;
} BST;

typedef struct treeNode {
	item key;
	struct treeNode* left;
	struct treeNode* right;
} treeNode;

void displayBST(treeNode* bt);
void searchBST(BST* bt, item data);
void insertBST(BST* bt, item data);

int main() {
	BST* p = NULL;
	item t;

	strcpy(t.itemCode, "12345");
	t.stock = 10;
	insertBST(p, t);

	return 0;
}

void displayBST(treeNode* bt) {
	treeNode* p = bt;
	printf("[system] ��ü ��� ���\n");
	if (p != NULL) {
		displayBST(p->left);
		printf("- ������ȣ: %s, ���: %d\n", p->key.itemCode, p->key.stock);
		displayBST(p->right);
	}
}

void insertBST(BST* bt, item data) {
	treeNode* p = bt->head;
	treeNode* parent = NULL;

	while (p != NULL) {
		if (data.itemCode == p->key.itemCode) {
			p->key.stock += data.stock;
			printf("[system] �����ϴ� ��ǰ�ڵ��Դϴ�.\n��ǰ�ڵ� %s�� ����� %d�� �Դϴ�.\n", p->key.itemCode, p->key.stock);
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

	if (bt->head == NULL)
		bt->head = newNode;
	else if (data.itemCode[0] < parent->key.itemCode[0])
		parent->left = newNode;
	else
		parent->right = newNode;
}