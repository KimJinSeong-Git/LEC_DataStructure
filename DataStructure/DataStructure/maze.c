#include "maze.h"

void loadMaze(int maze[][p + 2], char* fileRoot) {
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

	maze[1][1] = START;
	maze[m][p] = DST;
}

void printMaze(int maze[][p+2]) {
	int kind;
	for (int row = 0; row < m+2; row++) {
		for (int col = 0; col < p+2; col++) {
			kind = maze[row][col];
			switch (kind) {
			case OPEN:
				printf("  ");
				break;
			case CLOSED:
				printf("¡á");
				break;
			case START:
				printf("¨ß");
				break;
			case DST:
				printf("¨Ð");
				break;
			}
		}
		printf("\n");
	}
}