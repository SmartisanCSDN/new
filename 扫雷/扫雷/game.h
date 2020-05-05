#ifndef _GAME_H_
#define _GAME_H_


#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_MINE_COUNT 10

void play();
//��ʼ������
void InitBoard(char board[ROWS][COLS], int rows, int cols, char ch);
//����
void SetMine(char mine[ROWS][COLS], int row, int col);
//չʾ����
void DisplayBoard(char board[ROWS][COLS], int row, int col);
//����
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
//������Χ�׵ĸ���
int GetMineCount(char mine[ROWS][COLS], int x, int y);
//��չ����
Extension(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int row, int col);




#endif