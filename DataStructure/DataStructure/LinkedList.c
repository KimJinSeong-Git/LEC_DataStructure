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

	// ---------- 파일 읽어오기 ----------
	FILE* fp;
	char *fileRoot = "D:/Private/GitHub/LEC_DataStructure/resource/HW1/student.txt";
	fopen_s(&fp, fileRoot, "r");
	
	// 라인 별, 단어 별 구분하기
	int cntLine = 1;
	char fileBuffer[30];
	char* context = NULL;

	while (!feof(fp)) {
		fgets(fileBuffer, sizeof(fileBuffer), fp);				// 한 라인 buffer로 읽어오기
		printf("[Input] line %d\n", cntLine++);

		char* word = strtok_s(fileBuffer, " ", &context);	// 공백을 기준으로 Tokenize

		int cntWord = 1;
		while (word != NULL) {
			if (cntWord == 1) {
				printf("\t- 이름: %s\n", word);
				strcpy_s(tempData.name, sizeof(word), word);
				cntWord++;
			}
			else if (cntWord == 2) {
				printf("\t- 학번: %s\n", word);
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

	// ---------- 터미널 입력 ----------
	int power = 1;
	while (power) {
		char terminalBuffer[100];
		gets_s(terminalBuffer, sizeof(terminalBuffer));

		char* command = strtok_s(terminalBuffer, " ", &context);
		if (strcmp(command, "print") == 0)
			printList(student);
		else if (strcmp(command, "search") == 0)
			printf("search");
		else if (strcmp(command, "insert") == 0)
			printf("insert");
		else if (strcmp(command, "delete") == 0)
			printf("delete");
		else if (strcmp(command, "reverse") == 0)
			printf("reverse");
		else if (strcmp(command, "getLength") == 0)
			printf("getLength");
		else if (strcmp(command, "exit") == 0) {
			printf("exit");
			power = 0;
		}
	}


	return 0;
}

// ---------- Definition ----------
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
