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
void readFile(linkedList* L, char* fileRoot);
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

	// ---------- ���� �о���� ----------
	char *fileRoot = "C:/Users/YONSEI-IT/Desktop/������_�ٷ��л�/github/LEC_DataStructure/resource/HW1/student.txt";
	readFile(student, fileRoot);

	// ---------- �͹̳� �Է� ----------
	int power = 1;
	while (power) {
		char terminalBuffer[100];
		printf("$ ");
		gets_s(terminalBuffer, sizeof(terminalBuffer));

		char* cmdContext = NULL;
		char* command = strtok_s(terminalBuffer, " ", &cmdContext);		// ��ūȭ - ��ɾ� �ν�

		// ---------- Print ----------
		if (strcmp(command, "print") == 0)
			printList(student);

		// ---------- Search ----------
		else if (strcmp(command, "search") == 0) {
			int nbSearchID = atoi(strtok_s(NULL, " ", &cmdContext));		// ���� ���� ��ūȭ ����
			search(student, nbSearchID);								// �ش� ID Ž��
		}

		// ---------- Insert ----------
		else if (strcmp(command, "insert") == 0) {
			printf("[System] Insert\n");
			int nbSearchID = atoi(strtok_s(NULL, " ", &cmdContext));		// ���� ���� ��ūȭ ����
			listNode* searchedNode = search(student, nbSearchID);

			int newID = atoi(strtok_s(NULL, " ", &cmdContext));
			char* newName = strtok_s(NULL, " ", &cmdContext);
			listData newItem;

			newItem.id = newID;
			strcpy_s(newItem.name, sizeof(newItem.name), newName);

			int insert(student, searchedNode, newItem);
		}

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
void readFile(linkedList* L, char* fileRoot) {
	FILE* fp;
	listData tempData;

	fopen_s(&fp, fileRoot, "r");

	// ���� ��, �ܾ� �� �����ϱ�
	int cntLine = 1;
	char fileBuffer[30];
	char* context = NULL;

	while (!feof(fp)) {
		fgets(fileBuffer, sizeof(fileBuffer), fp);				// �� ���� buffer�� �о����

		char* word = strtok_s(fileBuffer, " ", &context);		// ������ �������� Tokenize

		int cntWord = 1;
		while (word != NULL) {
			if (cntWord == 1) {
				strcpy_s(tempData.name, sizeof(word), word);
				cntWord++;
			}
			else if (cntWord == 2) {
				tempData.id = atoi(word);
				cntWord++;
			}
			else
				printf("ERROR = %s\n", word);

			word = strtok_s(NULL, " ", &context);
		}
		insertLast(L, tempData);
	}
	fclose(fp);
	printf("[ System ] ���� �ҷ����� �Ϸ�.\n\n");
}

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
	printf("[ System ] Print List\n");
	
	p = L->head;
	while (p != NULL) {
		printf("- %s_%d", p->data.name, p->data.id);
		p = p->link;
		if (p != NULL)
			printf("\n");
	}
	printf("\n\n============================================\n\n");
}

listNode* search(linkedList* L, int x) {
	printf("[System] Search\n");

	listNode* searched;
	searched = L->head;				// ù ��° �׸��� �ּ�
	while (searched != NULL) {		// ���� ����Ʈ�� �ƴϸ� �ݺ�
		if (searched->data.id == x)
			break;					// Ž�� �����Ͱ� ���ٸ� �ݺ��� ����
		else
			searched = searched->link;		// ���� �ʴٸ� ���� ��� Ž��
	}

	if (searched != NULL)
		printf("- �й��� %d�� �л��� �̸�: %s\n", x, searched->data.name);
	else		// ������ ��ũ( NULL )�� ���� ��, ���ǿ� �´� ��尡 ����
		printf("- �й��� %d�� �л��� �����ϴ�.\n", x);
	printf("\n============================================\n\n");

	return searched;
}