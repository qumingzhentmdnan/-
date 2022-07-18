#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 3
#define COLUMN 3
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
void menu();
void test();
void game();
void creatboard(char board[ROW][COLUMN], int row, int column);
void printfboard(char board[ROW][COLUMN], int row, int column);
void playmove(char board[ROW][COLUMN], int row, int column);
void computermove(char board[ROW][COLUMN], int row, int column);
int iswin(char board[ROW][COLUMN], int row, int column);
int  isfull(char board[ROW][COLUMN], int row, int column);

