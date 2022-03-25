/*
[ 과제 내용 ]
-  Linked list 프로그램을 구현하고 실험한다. 

-  주어진 데이터를 linked list에 모두 저장하고, 새로운 데이터 추가, 기존 데이터 삭제, 검색, 
  리스트의 데이터 순서를 역순으로 재배치 하는 작업을 실험해본다.

-  삽입할 데이터는 텍스트 파일 students.txt에 들어 있는 학생 명단이며 각 학생의 명단은 이름(문자열)과 학번(정수)으로 구성된 구조체로 
  아래와 같이 정의한다.
*/
#include "linkedList.h"

int main() {
	linkedList* student = initList();

	// ---------- 파일 읽어오기 ----------
	char *fileRoot = "C:/Users/YONSEI-IT/Desktop/김진성_근로학생/github/LEC_DataStructure/resource/HW1/student.txt";
	readFile(student, fileRoot);

	int power = 1;
	while (power) {
		// ---------- 터미널 입력 ----------
		char terminalBuffer[100];
		printf("$ ");
		gets_s(terminalBuffer, sizeof(terminalBuffer));

		char* cmdContext = NULL;
		char* command = strtok_s(terminalBuffer, " ", &cmdContext);		// 토큰화 - 명령어 인식

		// ---------- Print ----------
		if (strcmp(command, "print") == 0) {
			printList(student);
		}

		// ---------- Search ----------
		else if (strcmp(command, "search") == 0) {
			int nbSearchID = atoi(strtok_s(NULL, " ", &cmdContext));		// 다음 인자 토큰화 진행
			search(student, nbSearchID);									// 해당 ID 탐색
		}

		// ---------- Insert ----------
		else if (strcmp(command, "insert") == 0) {
			int nbSearchID = atoi(strtok_s(NULL, " ", &cmdContext));		// 다음 인자 토큰화 진행
			listNode* searchedNode = search(student, nbSearchID);

			int newID = atoi(strtok_s(NULL, " ", &cmdContext));
			char* newName = strtok_s(NULL, " ", &cmdContext);

			listData newItem;
			newItem.id = newID;
			strcpy_s(newItem.name, sizeof(newItem.name), newName);

			insert(student, searchedNode, newItem);
		}

		// ---------- Delete ----------
		else if (strcmp(command, "delete") == 0) {
			int nbDeleteID = atoi(strtok_s(NULL, " ", &cmdContext));
			delete(student, nbDeleteID);
		}
		// ---------- Reverse ----------
		else if (strcmp(command, "reverse") == 0) {
			reverse(student);
		}

		// ---------- GetLength ----------
		else if (strcmp(command, "getLength") == 0) {
			getLength(student);
		}
		// ---------- Exit ----------
		else if (strcmp(command, "exit") == 0) {
			printf("[System] Exit Program\n");
			power = 0;
		}
		else {
			printf("[System] ERROR! Wrong Command. Please retype.\n");
		}
	}
	return 0;
}