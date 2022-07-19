#define _CRT_SECURE_NO_WARNINGS 1

#define ROW 9
#define COLUMN 9
#define ROWS ROW+2
#define COLUMNS COLUMN+2
#define EASY 80

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void initialboard(char fact[ROWS][COLUMNS], int row, int column, char set);
void printfboard(char show[ROWS][COLUMNS], int row, int column);
void setmine(char fact[ROWS][COLUMNS], int row, int column);
void movemine(char fact[ ROWS][COLUMNS], char show[ROWS][COLUMNS], int row, int column);
int addmine(char fact[ROWS][COLUMNS], int x, int y);