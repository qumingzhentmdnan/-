#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void test()
{
	printf("#################################\n");
	printf("######## 0.exit  1.play    ######\n");
	printf("#################################\n");
}
void menu()
{
	srand((unsigned int)time(NULL));
	test();
	printf("������:>\n");
	int input = 0;
	do
	{
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("�����˳���Ϸ:>\n");
			break;
		case 1:
			printf("����������Ϸ:>\n");
			game();
			break;
		default:
			printf("����Ƿ�������������:>\n");
			break;
		}
	} while (input);
}
void game()
{
	int ret = 0;
	char board[ROW][COLUMN] = { 0 };
	creatboard(board, ROW, COLUMN);
	printfboard(board, ROW, COLUMN);
	while (1)
	{
		playmove(board, ROW, COLUMN);
		printfboard(board, ROW, COLUMN);
		ret = iswin(board, ROW, COLUMN);
		if (ret != 'c')
			break;
		computermove(board, ROW, COLUMN);
		printfboard(board, ROW, COLUMN);
		ret = iswin(board, ROW, COLUMN);
		if (ret != 'c')
			break;
	}
	if (ret == '*')
		printf("���ʤ��\n");
	if (ret == '#')
		printf("����ʤ��\n");
	if (ret == 'q')
		printf("ƽ��\n");
}
int main()
{
	menu();
}