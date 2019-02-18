#include"ClearMineGame.h"
/*
*基本版：基本实现了扫雷游戏的功能
*/

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set) {
	memset(&board[0][0], set, rows*cols * sizeof(board[0][0]));
}
//显示棋盘
void DisplayBoard(char board[ROW][COL], int row, int col) {
	//遍历赋值输出
	for (int i = 0; i <= row; i++) {
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 1; i <= row; i++) {
		printf("%d ", i);
		for (int j = 1; j <= col; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("----------------------------\n");
}
//获取随机坐标值
int GetRandomIndex(int start, int end) {
	return rand() % (end - start + 1) + start;//返回end-start之间
}
//布置雷
void SetMine(char board[ROW][COL], int row, int col) {
	// 在随机坐标放置雷
	int count = DEFAULT_MINES;
	srand((unsigned long)time(NULL));
	while (count) {
		int x = GetRandomIndex(1, ROW);
		int y = GetRandomIndex(1, COL);
		if (board[x][y] == '0')//该位置不是雷才能布置
		{
			board[x][y] = '1';
			count--;
		}
	}
}
//清除雷
void FindMine(char mine[ROW][COL], char show[ROW][COL], int row, int col) {
	int x = 0, y = 0;
	while (1) {
		printf("输入要排查的坐标:\n");
		scanf("%d %d", &x, &y);
		char ch = 0;
		while ((ch = getchar()) != '\n' && ch != EOF) {

		}
		if (x >= 1 && x <= row&&y >= 1 && y <= col)
		{
			if (mine[x][y] == '1') {
				printf("遗憾，你被炸死了\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else {
				int count = GetMineCount(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, row, col);
			}
		}
		else {
			printf("输入坐标非法，请重新输入\n");

		}
	}


}
//获取坐标周围雷的数目
int GetMineCount(char mine[ROW][COL], int x, int y) {

	return mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0';
}
void game() {
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	SetMine(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	FindMine(mine, show, ROW, COL);
	DisplayBoard(show, ROW, COL);

}
