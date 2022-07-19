#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("#############################\n");
	printf("#####   0.quit  1.play  #####\n");
	printf("#############################\n");
}
void game()
{
	char show[ROWS][COLUMNS] = { 0 };
	char fact[ROWS][COLUMNS] = { 0 };
	initialboard(fact, ROWS, COLUMNS, '0');
	initialboard(show, ROWS, COLUMNS, '*');
	//printfboard(fact, ROW, COLUMN);
	printfboard(show, ROW, COLUMN);
	setmine(fact, ROW, COLUMN);
	printfboard(fact, ROW, COLUMN);
	movemine(fact, show, ROW, COLUMN);

}
void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	menu();
	do
	{
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("即将退出游戏\n");
			break;
		case 1:
			printf("即将进入游戏\n");
			game();
			break;
		default:
			printf("输入非法，请重新输入\n");
			break;
		}
	} 
	while (input);

}
int main()
{
	test();
	return 0;
}