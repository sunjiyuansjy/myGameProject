#include"ClearMineGame.h"
/**
* game2:��չ ��Χû��ʱչ��
*
*/

//��ʼ������
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set) {
	memset(&board[0][0], set, rows*cols * sizeof(board[0][0]));
}
//��ʾ����
void DisplayBoard(char board[ROW][COL], int row, int col) {
	//������ֵ���
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
//��ȡ�������ֵ
int GetRandomIndex(int start, int end) {
	return rand() % (end - start + 1) + start;//����end-start֮��
}
//������
void SetMine(char board[ROW][COL], int row, int col) {
	// ��������������
	int count = DEFAULT_MINES;
	srand((unsigned long)time(NULL));
	while (count) {
		int x = GetRandomIndex(1, row);
		int y = GetRandomIndex(1, col);
		if (board[x][y] == '0')//��λ�ò����ײ��ܲ���
		{
			board[x][y] = '1';
			count--;
		}
	}
}
//��ȡ������Χ�׵���Ŀ
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
//�����
void FindMine(char mine[ROW][COL], char show[ROW][COL], int row, int col) {
	int x = 0, y = 0;
	while (1) {
		printf("����Ҫ�Ų������:\n");
		scanf("%d %d", &x, &y);
		char ch = 0;
		while ((ch = getchar()) != '\n' && ch != EOF) {

		}
		if (x >= 1 && x <= row&&y >= 1 && y <= col)
		{
			if (mine[x][y] == '1') {
				printf("�ź����㱻ը����\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else {
				int count = GetMineCount(mine, x, y);
				show[x][y] = count + '0';
				OpenMine(mine, show, row, col, x, y);
				DisplayBoard(show, row, col);
			}
		}
		else {
			printf("��������Ƿ�������������\n");

		}
	}
}
//��չ�����ֱ���ģʽһ��
void SafeFindMine(char mine[ROW][COL], char show[ROW][COL], int row, int col) {
	int x = 0, y = 0; int x1 = 0, y1 = 0;//x1��y1Ϊ�״��Ų������
	printf("����Ҫ�Ų������:\n");
	scanf("%d %d", &x1, &y1);
	char ch = 0;
	while ((ch = getchar()) != '\n' && ch != EOF) {

	}
	if (x1 >= 1 && x1 <= row&&y1 >= 1 && y1 <= col)
	{
		if (mine[x1][y1] == '1')
		{
			printf("���ֱ���һ��\n");
			mine[x1][y1] = '0';
			DisplayBoard(mine, row, col);
			//Ų���׵�λ��
			if (mine[x][y] == '0' && (x1 != x) && (y1 != y))//��λ�ò����ײ��ܲ���
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
		printf("��������Ƿ�������������\n");

	}
}
//��Χ����ʱչ��
void OpenMine(char mine[ROW][COL], char show[ROW][COL], int row, int col, int x, int y)
{
	int count = GetMineCount(mine, x, y);
	if (count == 0) {
		if (mine[x][y] == '0') {
			show[x][y] = '0';
			if (x - 1 > 0 && y - 1 > 0 && show[x - 1][y - 1] == '0') {
				OpenMine(mine, show, row, col, x - 1, y - 1);
			}if (x - 1 > 0 && y > 0 && show[x - 1][y] == '0') {
				OpenMine(mine, show, row, col, x - 1, y);
			}if (x - 1 > 0 && y + 1 <= col && show[x - 1][y + 1] == '0') {
				OpenMine(mine, show, row, col, x - 1, y + 1);
			}if (x > 0 && y - 1 > 0 && show[x][y - 1] == '0') {
				OpenMine(mine, show, row, col, x, y - 1);
			}if (x > 0 && y + 1 <= col && show[x][y + 1] == '0') {
				OpenMine(mine, show, row, col, x, y + 1);
			}if (x + 1 <= row && y - 1 > 0 && show[x + 1][y - 1] == '0') {
				OpenMine(mine, show, row, col, x + 1, y - 1);
			}if (x + 1 <= row && y > 0 && show[x + 1][y] == '0') {
				OpenMine(mine, show, row, col, x + 1, y);
			}if (x + 1 <= row && y + 1 <= col && show[x + 1][y + 1] == '0') {
				OpenMine(mine, show, row, col, x + 1, y + 1);
			}
		}
		else {//����
			show[x][y] = count + '1';
		}
	}
}
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	SetMine(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	SafeFindMine(mine, show, ROW, COL);
	DisplayBoard(show, ROW, COL);
	FindMine(mine, show, ROW, COL);
	DisplayBoard(show, ROW, COL);
}
