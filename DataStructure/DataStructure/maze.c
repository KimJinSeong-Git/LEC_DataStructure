#include "maze.h"

void loadMaze(int* maze, char* fileRoot) {
	FILE* fp;
	char fileBuffer[30];
	char* context = NULL;
	int row, col;

	fopen_s(&fp, fileRoot, "r");
	row = 0;
	while (!feof(fp)) {
		fgets(fileBuffer, sizeof(fileBuffer), fp);
		char* cell = strtok_s(fileBuffer, " ", &context);

		while (cell != NULL) {
			printf("%s ", cell);
			cell = strtok_s(NULL, " ", &context);
		}
		printf("\n");
	}
}