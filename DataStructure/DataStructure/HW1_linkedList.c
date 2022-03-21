/*
[ 과제 내용 ]
-  Linked list 프로그램을 구현하고 실험한다. 

-  주어진 데이터를 linked list에 모두 저장하고, 새로운 데이터 추가, 기존 데이터 삭제, 검색, 
  리스트의 데이터 순서를 역순으로 재배치 하는 작업을 실험해본다.

-  삽입할 데이터는 텍스트 파일 students.txt에 들어 있는 학생 명단이며 각 학생의 명단은 이름(문자열)과 학번(정수)으로 구성된 구조체로 
  아래와 같이 정의한다.
*/
#include <stdio.h>

// 학생 명단 정의
typedef struct Listdata {
	char name[30];
	int id;
} listData;

// 리스트 노드 정의
typedef struct Listnode {
	listData data;
	struct ListNode* link;
} listNode;

// 리스트 헤드 정의
typedef struct LinkedList {
	listNode* head;
	int length;
} linkedList;

int main() {
	printf("test");

	return 0;
}