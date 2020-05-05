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
//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char ch);
//布雷
void SetMine(char mine[ROWS][COLS], int row, int col);
//展示棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col);
//排雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
//坐标周围雷的个数
int GetMineCount(char mine[ROWS][COLS], int x, int y);
//扩展函数
Extension(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int row, int col);




#endif