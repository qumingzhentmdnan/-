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
			printf("�����˳���Ϸ\n");
			break;
		case 1:
			printf("����������Ϸ\n");
			game();
			break;
		default:
			printf("����Ƿ�������������\n");
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