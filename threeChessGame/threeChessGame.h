#pragma once
#pragma warning (disable: 4996)
#include<stdio.h>
#include<windows.h>
#include<time.h>


#define ROW 3
#define COL 3

void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void CompMove(char board[ROW][COL], int row, int col);
void UserMove(char board[ROW][COL], int row, int col);
int isFull(char board[ROW][COL], int row, int col);
char JudgeWin(char board[ROW][COL], int row, int col);