#include "maze.h"

void loadMaze(int maze[][p+2], char* fileRoot) {
	FILE* fp;
	char fileBuffer[30];
	char* context = NULL;
	int row, col;

	fopen_s(&fp, fileRoot, "r");
	row = 0;
	while (!feof(fp)) {
		fgets(fileBuffer, sizeof(fileBuffer), fp);
		char* cell = strtok_s(fileBuffer, " ", &context);
		col = 0;
		while (cell != NULL) {
			maze[row][col] = atoi(cell);
			cell = strtok_s(NULL, " ", &context);
			
			col++;
		}
		row++;
	}
}

void printMaze(int maze[][p+2]) {
	for (int row = 0; row < m+2; row++) {
		for (int col = 0; col < p+2; col++) {
			if (maze[row][col] == 1)
				printf("бс");
			else if (maze[row][col] == 0)
				printf("бр");
		}
		printf("\n");
	}
}