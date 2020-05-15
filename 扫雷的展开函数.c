//À©Õ¹º¯Êý
Extension(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int row, int col)
{
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (i == 0 && j == 0)
				continue;
			int x1 = x + i;
			int y1 = y + j;
			if (x1 >= 1 && x1 <= row && y1 >= 1 && y1 <= col && show[x1][y1] == '*')
			{
				if (GetMineCount(mine, x1, y1) == 0)
				{
					show[x1][y1] = '0';
					Extension(mine, show, x1, y1, row, col);
				}
				else
				{
					show[x1][y1] = GetMineCount(mine, x1, y1) + '0';
				}
			}
		}
	}
}