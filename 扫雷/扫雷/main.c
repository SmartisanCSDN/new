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
		printf("��ѡ��:>");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			play();
			break;
		case 0:
			printf("�˳���Ϸ!!!\n");
			break;
		default:
			printf("�������!!!\n");
			break;
		}
	} while (choose);
	return 0;
}