#include "maze.h"

offsets move[Max_dir] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };
int maze[m + 2][p + 2];
int mark[m + 2][p + 2];

int main() {
	char* fileRoot = "./maze_14_2.txt";
	loadMaze(&maze, fileRoot);
	printMaze(&maze);
	return 0;
}