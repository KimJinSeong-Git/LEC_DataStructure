/*
[ ���� ���� ]
-  Linked list ���α׷��� �����ϰ� �����Ѵ�. 

-  �־��� �����͸� linked list�� ��� �����ϰ�, ���ο� ������ �߰�, ���� ������ ����, �˻�, 
  ����Ʈ�� ������ ������ �������� ���ġ �ϴ� �۾��� �����غ���.

-  ������ �����ʹ� �ؽ�Ʈ ���� students.txt�� ��� �ִ� �л� ����̸� �� �л��� ����� �̸�(���ڿ�)�� �й�(����)���� ������ ����ü�� 
  �Ʒ��� ���� �����Ѵ�.
*/
#include <stdio.h>

// �л� ��� ����
typedef struct Listdata {
	char name[30];
	int id;
} listData;

// ����Ʈ ��� ����
typedef struct Listnode {
	listData data;
	struct ListNode* link;
} listNode;

// ����Ʈ ��� ����
typedef struct LinkedList {
	listNode* head;
	int length;
} linkedList;

int main() {
	printf("test");

	return 0;
}