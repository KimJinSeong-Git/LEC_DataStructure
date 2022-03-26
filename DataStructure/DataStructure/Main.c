/*
[ ���� ���� ]
-  Linked list ���α׷��� �����ϰ� �����Ѵ�. 

-  �־��� �����͸� linked list�� ��� �����ϰ�, ���ο� ������ �߰�, ���� ������ ����, �˻�, 
  ����Ʈ�� ������ ������ �������� ���ġ �ϴ� �۾��� �����غ���.

-  ������ �����ʹ� �ؽ�Ʈ ���� students.txt�� ��� �ִ� �л� ����̸� �� �л��� ����� �̸�(���ڿ�)�� �й�(����)���� ������ ����ü�� 
  �Ʒ��� ���� �����Ѵ�.

- Github ���ε�
*/
#include "linkedList.h"

int main() {
	linkedList* student = initList();

	// ---------- ���� �о���� ----------
	char *fileRoot = "F:/github/LEC_DataStructure/resource/HW1/student.txt";
	readFile(student, fileRoot);

	int power = 1;
	while (power) {
		// ---------- �͹̳� �Է� ----------
		char terminalBuffer[100];
		printf("$ ");
		gets_s(terminalBuffer, sizeof(terminalBuffer));

		char* cmdContext = NULL;
		char* command = strtok_s(terminalBuffer, " ", &cmdContext);		// ��ūȭ - ��ɾ� �ν�

		// ---------- Print ----------
		if (strcmp(command, "print") == 0) {
			printList(student);
		}

		// ---------- Search ----------
		else if (strcmp(command, "search") == 0) {
			int nbSearchID = atoi(strtok_s(NULL, " ", &cmdContext));		// ���� ���� ��ūȭ ����
			search(student, nbSearchID);									// �ش� ID Ž��
		}

		// ---------- Insert ----------
		else if (strcmp(command, "insert") == 0) {
			int nbSearchID = atoi(strtok_s(NULL, " ", &cmdContext));		// ���� ���� ��ūȭ ����
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