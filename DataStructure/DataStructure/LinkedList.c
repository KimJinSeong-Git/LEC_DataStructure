/*
[ ���� ���� ]
-  Linked list ���α׷��� �����ϰ� �����Ѵ�. 

-  �־��� �����͸� linked list�� ��� �����ϰ�, ���ο� ������ �߰�, ���� ������ ����, �˻�, 
  ����Ʈ�� ������ ������ �������� ���ġ �ϴ� �۾��� �����غ���.

-  ������ �����ʹ� �ؽ�Ʈ ���� students.txt�� ��� �ִ� �л� ����̸� �� �л��� ����� �̸�(���ڿ�)�� �й�(����)���� ������ ����ü�� 
  �Ʒ��� ���� �����Ѵ�.
*/
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
linkedList* initList();
int getLength(linkedList* L);

void insertLast(linkedList* L, listData item);
int insert(linkedList* L, listNode* pre, listData item);
int delete(linkedList* L, int x);

listNode* search(linkedList* L, int x);
void printList(linkedList* L);

void reverse(linkedList* L);

// ---------- Main ----------
int main() {
	linkedList* student = initList();
	listData tempData;

	// ---------- ���� �о���� ----------
	FILE* fp;
	char *fileRoot = "D:/Private/GitHub/LEC_DataStructure/resource/HW1/student.txt";
	fopen_s(&fp, fileRoot, "r");
	
	// ���� ��, �ܾ� �� �����ϱ�
	int cntLine = 1;
	char fileBuffer[30];
	char* context = NULL;

	while (!feof(fp)) {
		fgets(fileBuffer, sizeof(fileBuffer), fp);				// �� ���� buffer�� �о����
		printf("[Input] line %d\n", cntLine++);

		char* word = strtok_s(fileBuffer, " ", &context);	// ������ �������� Tokenize

		int cntWord = 1;
		while (word != NULL) {
			if (cntWord == 1) {
				printf("\t- �̸�: %s\n", word);
				strcpy_s(tempData.name, sizeof(word), word);
				cntWord++;
			}
			else if (cntWord == 2) {
				printf("\t- �й�: %s\n", word);
				tempData.id = atoi(word);
				cntWord++;
			}
			else
				printf("ERROR = %s\n", word);

			word = strtok_s(NULL, " ", &context);
		}
		insertLast(student, tempData);
	}
	fclose(fp);

	// ---------- �͹̳� �Է� ----------
	int power = 1;
	while (power) {
		char terminalBuffer[100];
		gets_s(terminalBuffer, sizeof(terminalBuffer));

		char* command = strtok_s(terminalBuffer, " ", &context);	// ��ūȭ - ��ɾ� �ν�

		// ---------- Print ----------
		if (strcmp(command, "print") == 0)
			printList(student);

		// ---------- Search ----------
		else if (strcmp(command, "search") == 0)
			printf("[System] Search\n");

		// ---------- Insert ----------
		else if (strcmp(command, "insert") == 0)
			printf("[System] Insert\n");

		// ---------- Delete ----------
		else if (strcmp(command, "delete") == 0)
			printf("[System] Delete\n");

		// ---------- Reverse ----------
		else if (strcmp(command, "reverse") == 0)
			printf("[System] Reverse\n");

		// ---------- GetLength ----------
		else if (strcmp(command, "getLength") == 0)
			printf("[System] GetLength\n");

		// ---------- Exit ----------
		else if (strcmp(command, "exit") == 0) {
			printf("[System] Exit Program\n");
			power = 0;
		}
		else
			printf("[System] ERROR! Wrong Command. Please retype.\n");
	}
	return 0;
}

// ---------- Definition ----------
linkedList* initList() {
	linkedList* L;									// ����Ʈ ��� ����
	L = (linkedList*)malloc(sizeof(linkedList));	// �޸� �Ҵ�
	L->head = NULL;									// �������� �ʱ�ȭ
	L->length = 0;									// ��� ���� 0���� �ʱ�ȭ
	return L;
}

int getLength(linkedList* L) {
	return L->length;
}

void insertLast(linkedList* L, listData item) {
	// ���ο� ��� ����
	listNode *newNode, *temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;
	newNode->link = NULL;

	// ���鸮��Ʈ�̸� �ٷ� ����
	if (L->head == NULL) 
		L->head = newNode;

	// �ƴ϶�� ������ ��� Ž�� �� ����
	else {
		temp = L->head;					// ù ��° ����� �ּ� �Է�
		while (temp->link != NULL)		// ������ ��尡 �ƴϸ� ��� Ž��
			temp = temp->link;			// ���� ����� �ּ� �Է�
		temp->link = newNode;			// ������ ��� �ڿ� �� ��� ����
	}
}

void printList(linkedList* L) {
	listNode* p;
	printf("[ Print List ]\n");
	
	p = L->head;
	while (p != NULL) {
		printf("- %s_%d", p->data.name, p->data.id);
		p = p->link;
		if (p != NULL)
			printf("\n");
	}
	printf(")\n");
}
