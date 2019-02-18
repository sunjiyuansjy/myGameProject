#include"ClearMineGAME.h"

void menu() {
	printf("*******************扫雷游戏*****************\n");
	printf("*********1.play            2.exit***********\n");
	printf("****************请输入选项******************\n");

}

int main() {
	int input = 0;
	do {
		menu();
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
			break;
		case 2:
			exit(0);
			break;
		//case 3:game1(); break;
		default:printf("输入错误，请重输\n"); break;
		}
	} while (input);
	system("pause");
	return 0;
}