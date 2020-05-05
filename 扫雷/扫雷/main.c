#define _CRT_SECURE_NO_WARNINGS 1


#include"game.h"


void view()
{
	printf("***************************\n");
	printf("*****     [1]play     *****\n");
	printf("*****     [0]exit     *****\n");
	printf("***************************\n");
}

int main()
{
	int choose = 0;
	do
	{
		view();
		printf("请选择:>");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			play();
			break;
		case 0:
			printf("退出游戏!!!\n");
			break;
		default:
			printf("输入错误!!!\n");
			break;
		}
	} while (choose);
	return 0;
}