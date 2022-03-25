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
	printf("[System] Get Length \n");
	printf("- Length: %d", L->length);

	return L->length;
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
		printf("[System] Insert Fali.");
		return 0;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
	L->length++;
	printf("[System] Insert Complete.");
	printList(L);
	return 1;
}