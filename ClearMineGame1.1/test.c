#include"ClearMineGAME.h"

void menu() {
	printf("*******************ɨ����Ϸ*****************\n");
	printf("*********1.play            2.exit***********\n");
	printf("****************������ѡ��******************\n");

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
		default:printf("�������������\n"); break;
		}
	} while (input);
	system("pause");
	return 0;
}