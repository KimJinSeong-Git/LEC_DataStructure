/*
[ 과제 내용 ]
-  Linked list 프로그램을 구현하고 실험한다. 

-  주어진 데이터를 linked list에 모두 저장하고, 새로운 데이터 추가, 기존 데이터 삭제, 검색, 
  리스트의 데이터 순서를 역순으로 재배치 하는 작업을 실험해본다.

-  삽입할 데이터는 텍스트 파일 students.txt에 들어 있는 학생 명단이며 각 학생의 명단은 이름(문자열)과 학번(정수)으로 구성된 구조체로 
  아래와 같이 정의한다.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 학생 명단 정의
typedef struct Listdata {
	char name[30];
	int id;
} listData;

// 리스트 노드 정의
typedef struct ListNode {
	listData data;
	struct ListNode* link;
} listNode;

// 리스트 헤드 정의
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

	// ---------- 파일 읽어오기 ----------
	char *fileRoot = "C:/Users/YONSEI-IT/Desktop/김진성_근로학생/github/LEC_DataStructure/resource/HW1/student.txt";
	readFile(student, fileRoot);

	// ---------- 터미널 입력 ----------
	int power = 1;
	while (power) {
		char terminalBuffer[100];
		printf("$ ");
		gets_s(terminalBuffer, sizeof(terminalBuffer));

		char* cmdContext = NULL;
		char* command = strtok_s(terminalBuffer, " ", &cmdContext);	// 토큰화 - 명령어 인식

		// ---------- Print ----------
		if (strcmp(command, "print") == 0)
			printList(student);

		// ---------- Search ----------
		else if (strcmp(command, "search") == 0) {
			printf("[System] Search\n");
			int nbSearchID = atoi(strtok_s(NULL, " ", &cmdContext));	// 다음 인자 토큰화 진행
			search(student, nbSearchID);								// 해당 ID 탐색
		}

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
	return L->length;
}

void insertLast(linkedList* L, listData item) {
	// 새로운 노드 생성
	listNode *newNode, *temp;
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