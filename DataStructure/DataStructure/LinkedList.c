#include "linkedList.h"

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
	printf("[System] ���� �ҷ����� �Ϸ�.\n\n");
}

linkedList* initList() {
	linkedList* L;									// ����Ʈ ��� ����
	L = (linkedList*)malloc(sizeof(linkedList));	// �޸� �Ҵ�
	L->head = NULL;									// �������� �ʱ�ȭ
	L->length = 0;									// ��� ���� 0���� �ʱ�ȭ
	return L;
}

int getLength(linkedList* L) {
	printf("[System] Get Length \n");
	printf("- Length: %d\n\n", L->length);

	return L->length;
}

void printList(linkedList* L) {
	listNode* p;
	printf("[System] Print List\n");

	p = L->head;
	while (p != NULL) {
		printf("- %s_%d", p->data.name, p->data.id);
		p = p->link;
		if (p != NULL)
			printf("\n");
	}
	printf("\n\n");
}

listNode* search(linkedList* L, int x) {
	printf("[System] Search: %d\n", x);

	listNode* searched;
	searched = L->head;				// ù ��° �׸��� �ּ�
	while (searched != NULL) {		// ���� ����Ʈ�� �ƴϸ� �ݺ�
		if (searched->data.id == x)
			break;					// Ž�� �����Ͱ� ���ٸ� �ݺ��� ����
		else
			searched = searched->link;		// ���� �ʴٸ� ���� ��� Ž��
	}

	if (searched != NULL)
		printf("- Name: %s\n\n", searched->data.name);
	else		// ������ ��ũ( NULL )�� ���� ��, ���ǿ� �´� ��尡 ����
		printf("- Fail. Not Exist.\n\n");

	return searched;
}

void insertLast(linkedList* L, listData item) {
	// ���ο� ��� ����
	listNode* newNode, * temp;
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
	L->length++;
}

int insert(linkedList* L, listNode* pre, listData item) {
	printf("[System] Insert Start.\n");
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;
	newNode->link = NULL;

	if (L->head == NULL)
		L->head = newNode;
	else if (pre == NULL) {
		printf("[System] Insert Fali.\n\n");
		return 0;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
	L->length++;
	printf("[System] Insert Complete.\n\n");
	printList(L);
	return 1;
}

void reverse(linkedList* L) {
	printf("[System] Reverse Start\n");
	listNode *cur, *pre, *next;
	cur = L->head;
	pre = NULL;
	while (cur != NULL) {
		next = cur->link;
		cur->link = pre;
		pre = cur;
		cur = next;
	}
	L->head = pre;
	printf("[System] Reverse Complete.\n\n");
	printList(L);
}

int delete(linkedList* L, int x) {
	printf("[System] Delete\n");
	listNode* toDelete = search(L, x);	// ������ ����� ��ġ Ž��
	
	// ������ ��尡 �ִٸ�, �޸� ���� ����
	if (toDelete != NULL) {
		listNode* pre = L->head;
		while (pre->link != toDelete) {
			pre = pre->link;	// ���� ��� Ž��
		}
		pre->link = toDelete->link;							// ���� ���� ���� ��� ��ũ
		free(toDelete);										// �޸� ����
		printf("[System] Delete Complete.\n\n");
		printList(L);
		return 1;
	}
	else
		printf("[System] Delete Failed.\n\n");

	return 0;
}