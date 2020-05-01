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
	printf("��ѡ��:>");
}
int main()
{
	int value = 0;
	size_t index = 0;
	int choice;
	int capacity;
	List myList;
	printf("���������Ա�����:>");
	scanf("%d", &capacity);
	SeqListInit(&myList, capacity);
	while (1)
	{
		view();
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("������Ҫ�����ֵ:>");
			scanf("%d", &value);
			ListPushBack(&myList, value);
			break;
		case 2:
			printf("������Ҫ�����ֵ:>");
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
			List_show(&myList);
			break;
		case 6:
			printf("������Ҫ���ҵ�ֵ:>");
			scanf("%d", &value);
			index = ListFind(&myList, value);
			if (index == -1)
				printf("Ҫ���ҵ�Ԫ�ز�����!\n");
			else
				printf("������Ԫ�������Ա����״γ��ֵ�λ����:%d\n", index + 1);
			break;
		case 7:
			printf("������Ҫ�����λ��:>");
			scanf("%d", &index);
			printf("������Ҫ�����ֵ:>");
			scanf("%d", &value);
			SeqListInsert(&myList, index, value);
			break;
		case 8:
			printf("������Ҫɾ����λ��:>");
			scanf("%d", &index);
			SeqListErase(&myList, index);
			break;
		case 9:
			printf("������Ҫɾ����ֵ:>");
			scanf("%d", &value);
			SeqListRemove(&myList, value);
			break;
		case 10:
			printf("������Ҫ�޸ĵ�λ��:>");
			scanf("%d", &index);
			printf("������Ҫ�޸ĵ�ֵ:>");
			scanf("%d", &value);
			SeqListModify(&myList, index, value);
			break;
		}
	}
	return 0;
}