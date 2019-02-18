#include"ClearMineGame.h"

/**
*    ClearMineGame1.1 扩展了功能：第一次下子，不炸死。
*
**/


//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set) {
	memset(&board[0][0], set, rows*cols * sizeof(board[0][0]));
}
//显示棋盘
void DisplayBoard(char board[ROW][COL], int row, int col) {
	//遍历赋值输出
	for (int i = 0; i <= row; i++) {
		printf("%d ", i);//列号
	}
	printf("\n");
	for (int i = 1; i <= row; i++) {
		
		printf("%d ", i);//行号
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
	 //在随机坐标放置雷
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
//扩展：新手保护模式一次
void SafeFindMine(char mine[ROW][COL], char show[ROW][COL], int row, int col) {
	int x = 0, y = 0; int x1 = 0, y1 = 0;//x1和y1为首次排查的坐标
		printf("输入要排查的坐标:\n");
		scanf("%d %d", &x1, &y1);
		char ch = 0;
		while ((ch = getchar()) != '\n' && ch != EOF) {

		}
		if (x1>= 1 && x1 <= row&&y1 >= 1 && y1 <= col)
		{
			if (mine[x1][y1] == '1')
			{
				printf("新手保护一次\n");
				mine[x1][y1] ='0';
				DisplayBoard(mine, row, col);
				//挪动雷的位置
				if (mine[x][y] == '0'&&(x1!=x)&&(y1!=y))//该位置不是雷才能布置
				{
					mine[x][y] = '1';	
				}
			}
			else {
				int count = GetMineCount(mine, x1, y1);
				show[x1][y1] = count + '0';
				DisplayBoard(show, row, col);
			}
		}
		else {
			printf("输入坐标非法，请重新输入\n");

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
		if (x >= 1 && x <= row && y >= 1 && y <= col)
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
		mine[x + 1][y + 1] -8 * '0';
}
void game() {
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	SetMine(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	SafeFindMine(mine,show,ROW, COL);
	DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	FindMine(mine, show, ROW, COL);
	DisplayBoard(show, ROW, COL);

}
