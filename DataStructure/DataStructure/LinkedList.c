#include "linkedList.h"

void readFile(linkedList* L, char* fileRoot) {
	FILE* fp;
	listData tempData;

	fopen_s(&fp, fileRoot, "r");

	// 라인 별, 단어 별 구분하기
	int cntLine = 1;
	char fileBuffer[30];
	char* context = NULL;

	while (!feof(fp)) {
		fgets(fileBuffer, sizeof(fileBuffer), fp);				// 한 라인 buffer로 읽어오기

		char* word = strtok_s(fileBuffer, " ", &context);		// 공백을 기준으로 Tokenize

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
	printf("[ System ] 파일 불러오기 완료.\n\n");
}

linkedList* initList() {
	linkedList* L;									// 리스트 헤드 생성
	L = (linkedList*)malloc(sizeof(linkedList));	// 메모리 할당
	L->head = NULL;									// 공백으로 초기화
	L->length = 0;									// 노드 개수 0으로 초기화
	return L;
}

int getLength(linkedList* L) {
	printf("[System] Get Length \n");
	printf("- Length: %d", L->length);
	printf("\n\n============================================\n\n");

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
	printf("\n\n============================================\n\n");
}

listNode* search(linkedList* L, int x) {
	printf("[System] Search\n");

	listNode* searched;
	searched = L->head;				// 첫 번째 항목의 주소
	while (searched != NULL) {		// 공백 리스트가 아니면 반복
		if (searched->data.id == x)
			break;					// 탐색 데이터가 같다면 반복문 종료
		else
			searched = searched->link;		// 같지 않다면 다음 노드 탐색
	}

	if (searched != NULL)
		printf("- 학번이 %d인 학생의 이름: %s\n", x, searched->data.name);
	else		// 마지막 링크( NULL )에 도달 즉, 조건에 맞는 노드가 없음
		printf("- 학번이 %d인 학생이 없습니다.\n", x);
	printf("\n============================================\n\n");

	return searched;
}

void insertLast(linkedList* L, listData item) {
	// 새로운 노드 생성
	listNode* newNode, * temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;
	newNode->link = NULL;

	// 공백리스트이면 바로 삽입
	if (L->head == NULL) 
		L->head = newNode;
	// 아니라면 마지막 노드 탐색 후 삽입
	else {
		temp = L->head;					// 첫 번째 노드의 주소 입력
		while (temp->link != NULL)		// 마지막 노드가 아니면 계속 탐색
			temp = temp->link;			// 다음 노드의 주소 입력
		temp->link = newNode;			// 마지막 노드 뒤에 새 노드 연결
	}
	L->length++;
}

int insert(linkedList* L, listNode* pre, listData item) {
	printf("[System] Insert\n");
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;
	newNode->link = NULL;

	if (L->head == NULL)
		L->head = newNode;
	else if (pre == NULL) {

	}
	printf("\n\n============================================\n\n");
}