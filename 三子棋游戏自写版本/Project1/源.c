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
	printf("请输入:>\n");
	int input = 0;
	do
	{
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("即将退出游戏:>\n");
			break;
		case 1:
			printf("即将进入游戏:>\n");
			game();
			break;
		default:
			printf("输入非法，请重新输入:>\n");
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
		printf("玩家胜利\n");
	if (ret == '#')
		printf("电脑胜利\n");
	if (ret == 'q')
		printf("平局\n");
}
int main()
{
	menu();
}