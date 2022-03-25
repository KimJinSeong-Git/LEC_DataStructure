/*
[ ���� ���� ]
-  Linked list ���α׷��� �����ϰ� �����Ѵ�. 

-  �־��� �����͸� linked list�� ��� �����ϰ�, ���ο� ������ �߰�, ���� ������ ����, �˻�, 
  ����Ʈ�� ������ ������ �������� ���ġ �ϴ� �۾��� �����غ���.

-  ������ �����ʹ� �ؽ�Ʈ ���� students.txt�� ��� �ִ� �л� ����̸� �� �л��� ����� �̸�(���ڿ�)�� �й�(����)���� ������ ����ü�� 
  �Ʒ��� ���� �����Ѵ�.
*/
#include "linkedList.h"

int main() {
	linkedList* student = initList();

	// ---------- ���� �о���� ----------
	char *fileRoot = "C:/Users/YONSEI-IT/Desktop/������_�ٷ��л�/github/LEC_DataStructure/resource/HW1/student.txt";
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
			printf("\n\n============================================\n\n");
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
			printf("\n\n============================================\n\n");
		}

		// ---------- Delete ----------
		else if (strcmp(command, "delete") == 0) {
			printf("[System] Delete\n");
			printf("\n\n============================================\n\n");
		}
		// ---------- Reverse ----------
		else if (strcmp(command, "reverse") == 0) {
			printf("[System] Reverse\n");
			printf("\n\n============================================\n\n");
		}

		// ---------- GetLength ----------
		else if (strcmp(command, "getLength") == 0) {
			getLength(student);
			printf("\n\n============================================\n\n");
		}
		// ---------- Exit ----------
		else if (strcmp(command, "exit") == 0) {
			printf("[System] Exit Program\n");
			power = 0;
			printf("\n\n============================================\n\n");
		}
		else {
			printf("[System] ERROR! Wrong Command. Please retype.\n");
			printf("\n\n============================================\n\n");
		}
	}
	return 0;
}