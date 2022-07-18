#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void creatboard(char board[ROW][COLUMN], int row, int column)
{
	int a = 0;
	int b = 0;
	for (a = 0; a < row; a++)
	{
		for (b = 0; b < column; b++)
		{
			board[a][b] = ' ';
		}
	}
}
void printfboard(char board[ROW][COLUMN], int row, int column)
{
	int a = 0;
	int b = 0;
	for (a=0;a<row;a++)
	{
		for (b = 0; b < column; b++)
		{
			printf(" %c ", board [a][b]);
			if (b < column - 1)
				printf("|");
		}
		printf("\n");
		if (a < row - 1)
		{
			for (b = 0; b < column; b++)
			{
				printf("---");
				if (b < column - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}
void playmove(char board[ROW][COLUMN], int row, int column)
{
	printf("请玩家落子\n");
	int a = 0;
	int b = 0;
	while (1)
	{
		scanf("%d%d", &a, &b);
		if ((a >= 1 && a <= 3) && (b >= 1 && b <= 3))
		{
			if (board[a - 1][b - 1] == ' ')
			{
				board[a - 1][b - 1] = '*';
				break;
			}
			else
				printf("输入非法,请重新输入\n");
		}
		else
			printf("输入非法，请重新输入\n");
	}
}
void computermove(char board[ROW][COLUMN], int row, int column)
{
	printf("电脑落子:>\n");
	while (1)
	{
		int x = 0;
		int y = 0;
		x = rand() % row;
		y = rand() % column;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
int iswin(char board[ROW][COLUMN], int row, int column)
{
	int a = 0;
	for (a = 0; a < row; a++)
	{
		if ((board[a][0]==board[a][1]) && (board[a][1] == board[a][2]) && board[a][0] != ' ')
			return board[a][0];
	}
	for (a = 0; a < column; a++)
	{
		if ((board[0][a] == board[1][a]) && (board[1][a] == board[2][a]) && board[0][a] != ' ')
			return board[0][a];
	}
	if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && board[1][1] != ' ')
		return board[1][1];
	if ((board[2][0] == board[1][1]) && (board[1][1] == board[0][2]) && board[1][1] != ' ')
		return board[1][1];
	if (isfull(board, ROW, COLUMN) == 1)
		return 'c';
	else
		return 'q';
}
int  isfull(char board[ROW][COLUMN], int row, int column)
{
	int a = 0;
	int b = 0;
	for (a = 0; a < row; a++)
	{
		for (b = 0; b < column; b++)
		{
			if (board[a][b] == ' ')
			{
				return 1;
				break;
			}
		}
	}
	return 0;
}