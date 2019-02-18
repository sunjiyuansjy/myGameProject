#pragma once
#pragma warning (disable:4996)
#include<stdio.h>
#include<windows.h>
#include<time.h>
#include < stdlib.h>


#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define DEFAULT_MINES 20

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
void DisplayBoard(char board[ROW][COL], int row, int col);
int GetRandomIndex(int start, int end);
void SetMine(char board[ROW][COL], int row, int col);
int GetMineCount(char mine[ROW][COL], int x, int y);
void FindMine(char mine[ROW][COL], char show[ROW][COL], int row, int col);
//void OpenMine(char mine[ROW][COL], char show[ROW][COL], int row, int col);
//void SafeFindMine(char mine[ROW][COL], char show[ROW][COL], int row, int col);


