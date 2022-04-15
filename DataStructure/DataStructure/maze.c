#include "maze.h"

void loadMaze(int maze[][p], char* fileRoot) {
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