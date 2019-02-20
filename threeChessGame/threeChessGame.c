
#include"threeChessGame.h"

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col) {
	//把数组初始化为空格
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			board[i][j] = ' ';
		}
	}
	//memset(&board[0][0],' ',row*col*sizeof(board[0][0])); //可以将整块内存设置
}
//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1) {
			for (int j = 0; j < col; j++) {
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}
void CompMove(char board[ROW][COL], int row, int col) {
	int x = 0; int y = 0;
	printf("电脑走\n");

	while (1) {
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ') {
			board[x][y] = 'O';
			break;
		}
	}

}
void UserMove(char board[ROW][COL], int row, int col) {
	int x = 0; int y = 0;
	printf("玩家走\n");
	while (1) {
		printf("输入坐标\n");
		scanf("%d %d", &x, &y);
		//需要判断输入的坐标是否合法
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = 'X';
				break;
			}
			else {
				printf("坐标已经被占用，请重新输入\n");
			}
		}
		else {
			printf("输入坐标不合法，请重新输入\n");
		}
	}
}
//判断棋盘满没
int isFull(char board[ROW][COL], int row, int col) {
	//遍历棋盘
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (board[i][j] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}
char JudgeWin(char board[ROW][COL], int row, int col) {
	//1.玩家赢返回X，2.电脑赢返回O，3.平局返回Q，4.都没赢继续下返回N
	//一行都是同一个字符
	for (int i = 0; i < row; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
			return board[i][0];
		}
	}
	//一列都是同一个字符
	for (int j = 0; j < col; j++) {
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
			return board[j][0];
		}
	}
	//对角线都是同一个字符
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ') {
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ') {
		return board[1][1];
	}
	//没人赢的时候才能判断平局，此时棋盘应该满了
	if (isFull(board, row, col) == 1) {
		return 'Q';
	}
	return ' ';
	
}


void game() {
	char board[ROW][COL] = { 0 };
	char ret = 0;
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	while (1) {
		UserMove(board, ROW, COL);
		ret = JudgeWin(board, ROW, COL);
		if (ret != ' ') {
			break;
		}
		DisplayBoard(board, ROW, COL);
		CompMove(board, ROW, COL);
		ret = JudgeWin(board, ROW, COL);
		if (ret != ' ') {
			break;
		}
		DisplayBoard(board, ROW, COL);
	}
	
	DisplayBoard(board, ROW, COL);
	if (ret == 'X') {
		printf("玩家赢了\n");
	}
	else if (ret == 'O') {
		printf("电脑赢了\n");
	}
	else if (ret == 'Q') {
		printf("平局\n");
	}

}
void menu() {
	printf("***************************\n");
	printf("**1.play           2.exit**\n");
	printf("***************************\n");
	printf("select:\n");
}


