#define _CRT_SECURE_NO_WARNINGS 1

#include"list.h"



//初始化单链表
void ListInit(List * pl)
{
	pl->Head = NULL;
}

//尾插
void ListPushBack(List * pl, ListType value)
{
	assert(pl != NULL);

	if (pl->Head == NULL)
	{
		ListNode *p = (ListNode *)malloc(sizeof(ListNode));
		assert(p != NULL);
		p->data = value;
		p->next = NULL;

		pl->Head = p;
		printf("插入成功！\n");
	}
	else
	{
		//找链表尾节点
		ListNode *p = pl->Head;
		while (p->next != NULL)
			p = p->next;

		//申请一个新节点
		ListNode *s = (ListNode *)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = value;
		s->next = NULL;

		//挂在尾部
		p->next = s;
		printf("插入成功！\n");
	}
}


//头插
void ListPushFront(List * pl, ListType value)
{
	assert(pl != NULL);

	//申请一个新节点
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	assert(p != NULL);
	p->data = value;
	p->next = NULL;

	// 插入头部
	p->next = pl->Head;
	pl->Head = p;
	printf("插入成功！\n");
}

//尾删
void ListPopBack(List * pl)
{
	assert(pl != NULL);
	if (pl->Head == NULL)
		printf("链表已空，无法删除！\n");
	else
	{
		ListNode * p = pl->Head;
		if (p->next == NULL)   //只有一个节点时
		{
			free(p);
			pl->Head = NULL;
			printf("删除成功！\n");
		}
		else       //多个节点
		{
			while (p->next->next != NULL)
				p = p->next;
			free(p->next);
			p->next = NULL;
			printf("删除成功！\n");
		}
	}
}

//头删
void ListPopFront(List * pl)
{
	assert(pl != NULL);
	if (pl->Head == NULL)
		printf("链表已空，无法删除！\n");
	else
	{
		ListNode * p = pl->Head;
		pl->Head = p->next;
		free(p);
		printf("删除成功！\n");
	}
}

//查找
size_t ListFind(List pl, ListType value)
{
	ListNode *p = pl.Head;
	int count = 1;
	while (p != NULL)
	{
		if (p->data == value)
			return count;
		p = p->next;
		count++;
	}
	return -1;
}

//展示线性表
void ListShow(List pl)
{
	ListNode *p = pl.Head;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

//任意地方插入
void ListInsert(List * pl, size_t index, ListType value)
{
	assert(pl != NULL);
	ListNode * p = pl->Head;
	if (index == 1)       //往第一个位置插入
	{
		ListNode * s = (ListNode *)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = value;
		s->next = NULL;

		s->next = pl->Head;
		pl->Head = s;
		printf("插入成功！\n");
	}
	else
	{
		int count = 2; //标识位置
		while (p != NULL)
		{
			if (count == index)   //找到了
			{
				ListNode * s = (ListNode *)malloc(sizeof(ListNode));
				assert(s != NULL);
				s->data = value;
				s->next = NULL;

				s->next = p->next;
				p->next = s;
				printf("插入成功！\n");
				break;
			}
			p = p->next;
			count++;
		}
		if (p == NULL)  //没找到
			printf("位置不合适，无法插入！\n");
	}
}


//任意地方删除
void ListErase(List * pl, size_t index)
{
	assert(pl != NULL);
	if (pl->Head == NULL)
		printf("链表已空，无法删除！\n");
	else
	{
		ListNode * p = pl->Head;
		if (index == 1)  //删除第一个位置
		{
			pl->Head = p->next;
			free(p);
			printf("删除成功！\n");
		}
		else
		{
			int count = 2, flag = 0; //flag用于标识在循环结束时有没有找到
			while (p->next != NULL)
			{
				if (count == index)
				{
					ListNode * s = p->next;
					p->next = s->next;
					free(s);
					printf("删除成功！\n");
					flag = 1;
					break;
				}
				p = p->next;
				count++;
			}
			if (flag == 0) //不用 p==NULL 是因为删最后一个时完了p也为NULL
				printf("位置不合适，无法删除！\n");
		}
	}
}


//按值删除
void ListRemove(List * pl, ListType value)
{
	assert(pl != NULL);
	if (pl->Head == NULL)
	{
		printf("链表为空，无法删除！\n");
		return;
	}
	ListNode * p = pl->Head;
	while (p->next != NULL)
	{
		if (p->next->data == value)
		{
			ListNode * s = p->next;
			p->next = s->next;
			free(s);
		}
		else
			p = p->next;
	}
	if (pl->Head->data == value)
	{
		p = pl->Head;
		pl->Head = p->next;

	}
	printf("删除成功！\n");
}


//修改
void ListModify(List *pl, size_t index, ListType value)
{
	assert(pl != NULL);
	int count = 1;
	ListNode * p = pl->Head;
	while (p != NULL)
	{
		if (index == count)
		{
			p->data = value;
			printf("修改成功！\n");
			break;
		}
		p = p->next;
		count++;
	}
	if (p == NULL)
		printf("位置不合适，无法修改！\n");
}




/*
void text()
{
	List myList;
	ListInit(&myList);
	//ListCreate_Tail(&myList);
	ListCreate_Head(&myList);
	ListShow(myList);
}


//初始化单链表
void ListInit(List * pl)
{
	(*pl) = (ListNode *)malloc(sizeof(ListNode));
	assert(*pl != NULL);
	(*pl)->data = 2020;
	(*pl)->next = NULL;
}

//尾插法建表
void ListCreate_Tail(List * pl)
{
	assert(pl != NULL && (*pl) != NULL);
	ListNode * p = *pl;
	for (int i = 1; i <= 10; i++)
	{
		ListNode * s = (ListNode *)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;

		p->next = s;
		p = s;
	}
}

//头插法建表
void ListCreate_Head(List * pl)
{
	assert(pl != NULL && (*pl) != NULL);
	for (int i = 1; i <= 10; i++)
	{
		ListNode * p = (ListNode *)malloc(sizeof(ListNode));
		assert(p != NULL);
		p->data = i;
		p->next = NULL;

		p->next = (*pl)->next;
		(*pl)->next = p;
	}
}

//展示线性表
void ListShow(List pl)
{
	assert(pl != NULL);
	ListNode * p = pl->next;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over\n");

}





/*不带头结点 

//初始化单链表
void ListInit(List * pl)
{ //这里的List类型本来就是ListNode的指针类型，pl为指向List指针的指针，为二级指针
	(*pl) = NULL;
}

//尾插法建表
void ListCreate_Tail(List * pl)
{
	//先建立第一个节点
	*pl = (ListNode *)malloc(sizeof(ListNode));
	assert(*pl != NULL);
	(*pl)->data = 1;
	(*pl)->next = NULL;

	//创建一个活动指针p指向第一个节点
	ListNode * p = *pl;
	for (int i = 2; i <= 10; i++)
	{
		//新建一个节点，并创建一个活动指针s指向它
		ListNode * s = (ListNode *)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;

		//将s链接到链表上
		p->next = s;

		//将p指向s也就是链表最后一个节点准备下一次循环
		p = s;
	}

}

//头插法建表
void ListCreate_Head(List * pl)
{
	for (int i = 1; i <= 10; i++)
	{
		//新建一个节点，并创建一个活动指针p指向它
		ListNode * p = (ListNode *)malloc(sizeof(ListNode));
		assert(p != NULL);
		p->data = i;
		p->next = NULL;

		//将p头插到链表中
		p->next = *pl;
		*pl = p;
	}
}

//展示线性表
void ListShow(List pl)
{
	ListNode * p = pl;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}
*/