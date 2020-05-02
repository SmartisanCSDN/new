#define _CRT_SECURE_NO_WARNINGS 1

#include"list.h"

void view()
{
	printf("*************************************\n");
	printf("*   [1]push_back    [2]push_front   *\n");
	printf("*   [3]pop_back     [4]pop_front    *\n");
	printf("*   [5]show_myList  [6]find         *\n");
	printf("*   [7]insert_any   [8]delete_any   *\n");
	printf("*   [9]remove_value [10]modify      *\n");
	printf("*************************************\n");
	printf("请选择:>");
}
int main()
{
	int value = 0;
	size_t index = 0;
	int choice;
	List myList;
	ListInit(&myList);
	while (1)
	{
		view();
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("请输入要插入的值:>");
			scanf("%d", &value);
			ListPushBack(&myList, value);
			break;
		case 2:
			printf("请输入要插入的值:>");
			scanf("%d", &value);
			ListPushFront(&myList, value);
			break;
		case 3:
			ListPopBack(&myList);
			break;
		case 4:
			ListPopFront(&myList);
			break;
		case 5:
			ListShow(myList);
			break;
		case 6:
			printf("请输入要查找的值:>");
			scanf("%d", &value);
			index = ListFind(myList, value);
			if (index == -1)
				printf("要查找的元素不存在!\n");
			else
				printf("所查找元素首次出现在第%d个节点\n", index);
			break;
		case 7:
			printf("请输入要插入的位置:>");
			scanf("%d", &index);
			printf("请输入要插入的值:>");
			scanf("%d", &value);
			ListInsert(&myList, index, value);
			break;
		case 8:
			printf("请输入要删除的位置:>");
			scanf("%d", &index);
			ListErase(&myList, index);
			break;
		case 9:
			printf("请输入要删除的值:>");
			scanf("%d", &value);
			ListRemove(&myList, value);
			break;
		case 10:
			printf("请输入要修改的位置:>");
			scanf("%d", &index);
			printf("请输入要修改的值:>");
			scanf("%d", &value);
			ListModify(&myList, index, value);
			break;
		}
	}
	return 0;
}