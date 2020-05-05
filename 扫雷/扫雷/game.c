#define _CRT_SECURE_NO_WARNINGS 1


#include"game.h"


void play()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//布雷
	srand((unsigned int)time(NULL));
	SetMine(mine, ROW, COL);
	//展示棋盘
	system("cls");
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//排雷
	FindMine(mine, show, ROW, COL);
}

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char ch)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			board[i][j] = ch;
	}
}

//布雷
void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY_MINE_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

//展示棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	printf("0  ");
	for (int i = 1; i <= col; i++)
		printf("%d ", i);
	printf("\n\n");
	for (int i = 1; i <= row; i++)
	{
		printf("%d  ", i);
		for (int j = 1; j <= col; j++)
			printf("%c ", board[i][j]);
		printf("\n");
	}
}


//排雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int nomine = 0;
	int x = 0, y = 0;
	while (nomine < row * col - EASY_MINE_COUNT)
	{
		printf("请选择排查坐标:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				system("cls");
				printf("很遗憾,你被炸死了!!!\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else
			{
				nomine++;
				if (nomine == row * col - EASY_MINE_COUNT)
				{
					system("cls");
					printf("恭喜你,扫雷成功!!!\n");
					DisplayBoard(mine, ROW, COL);
					break;
				}
				int count = GetMineCount(mine, x, y);
				if (count == 0)
				{
					show[x][y] = '0';
					//Extension(mine, show, x, y, row, col);
				}
				else
				{
					show[x][y] = count + '0';
				}
				system("cls");
				DisplayBoard(show, ROW, COL);
			}
		}
		else
		{
			printf("坐标有误,请重新输入!!!\n");
		}
	}
	
}

//坐标周围雷的个数
int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return	mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1]
			+ mine[x][y - 1] + mine[x][y + 1] -8 * '0'+
			mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1];
}

//扩展函数
Extension(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int row, int col)
{
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (i == 0 && j == 0)
					continue;
			x = x + i;
			y = y + j;
			if (x >= 1 && x <= row && y >= 1 && y <= col)
			{
				if (GetMineCount(mine, x, y) == 0)
				{
					show[x][y] = '0';
					Extension(mine, show, x, y, row, col);
				}
				else
				{
					show[x][y] = GetMineCount(mine, x, y) + '0';
				}
			}
		}
	}
}