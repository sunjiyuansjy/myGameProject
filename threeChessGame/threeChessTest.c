#include"threeChessGame.h"



int main() {
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
			break;
		case 2:
			exit(0); printf("exit\n");
			break;
		default:
			printf("enter again\n");
			break;
		}
	} while (input);


	system("pause");
	return 0;
}