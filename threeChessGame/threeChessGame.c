
#include"threeChessGame.h"

//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col) {
	//�������ʼ��Ϊ�ո�
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			board[i][j] = ' ';
		}
	}
	//memset(&board[0][0],' ',row*col*sizeof(board[0][0])); //���Խ������ڴ�����
}
//��ӡ����
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
	printf("������\n");

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
	printf("�����\n");
	while (1) {
		printf("��������\n");
		scanf("%d %d", &x, &y);
		//��Ҫ�ж�����������Ƿ�Ϸ�
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = 'X';
				break;
			}
			else {
				printf("�����Ѿ���ռ�ã�����������\n");
			}
		}
		else {
			printf("�������겻�Ϸ�������������\n");
		}
	}
}
//�ж�������û
int isFull(char board[ROW][COL], int row, int col) {
	//��������
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
	//1.���Ӯ����X��2.����Ӯ����O��3.ƽ�ַ���Q��4.��ûӮ�����·���N
	//һ�ж���ͬһ���ַ�
	for (int i = 0; i < row; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
			return board[i][0];
		}
	}
	//һ�ж���ͬһ���ַ�
	for (int j = 0; j < col; j++) {
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
			return board[j][0];
		}
	}
	//�Խ��߶���ͬһ���ַ�
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ') {
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ') {
		return board[1][1];
	}
	//û��Ӯ��ʱ������ж�ƽ�֣���ʱ����Ӧ������
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
		printf("���Ӯ��\n");
	}
	else if (ret == 'O') {
		printf("����Ӯ��\n");
	}
	else if (ret == 'Q') {
		printf("ƽ��\n");
	}

}
void menu() {
	printf("***************************\n");
	printf("**1.play           2.exit**\n");
	printf("***************************\n");
	printf("select:\n");
}


