#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void initialboard(char fact[ROWS][COLUMNS], int row, int column, char set)
{
	int a = 0;
	int b = 0;
	for (a = 0; a < row; a++)
	{
		for (b = 0; b < column; b++)
		{
			fact[a][b] = set;
		}
	}
}
void printfboard(char show[ROWS][COLUMNS], int row, int column)
{
	int a = 0;
	int b = 0;
	for (a = 0; a <=column; a++)
	{
		printf("%d ", a);
	}
	printf("\n"); 
	for (a = 1; a <=row; a++)
	{
		printf("%d ", a);
		for (b = 1; b <=column; b++)
		{
			printf("%c ", show[a][b]);
		}
		printf("\n");
	}
	printf("\n");
}
void setmine(char fact[ROWS][COLUMNS], int row, int column)
{
	int count = EASY;
	while (count )
	{
		int a = rand() % row+1;
		int b = rand() % column+1;
		if (fact[a][b] == '0')
		{
			fact[a][b] = '1';
			count--;
		}

	}
}
int addmine(char fact[ROWS][COLUMNS], int x, int y)
{
	return fact[x - 1][y - 1] + fact[x - 1][y] + fact[x - 1][y + 1] + 
		fact[x][y - 1] + fact[x][y + 1] + fact[x + 1][y - 1] + fact[x + 1][y] + fact[x + 1][y + 1] - 8 * '0';
}
void movemine(char fact[ROWS][COLUMNS], char show[ROWS][COLUMNS], int row, int column)
{
	int x = 0;
	int y = 0;
	printf("请输入排雷坐标\n");
		while (1)
		{
			int win = 0;
			scanf("%d%d", &x, &y);
			if ((x <= row && x >= 1) && (y <= column && y >= 1))
			{
				if (fact[x][y] == '1')
				{
					printf("很遗憾，你被炸死了\n");
					printfboard(fact, ROW, COLUMN);
						break;
				}
				else
				{
					int count = addmine(fact, x, y);
					show[x][y] = count+'0';
					printfboard(show, row, column);
					win++;
				}
			}
			else
				printf("输入非法，请重新输入\n");
			if (win == row * column - EASY)
			{
				printf("恭喜你，扫雷成功\n");
				printfboard(fact, ROW, COLUMN);
			}
		}
}