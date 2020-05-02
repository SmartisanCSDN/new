#define _CRT_SECURE_NO_WARNINGS 1

#include"list.h"



//��ʼ��������
void ListInit(List * pl)
{
	pl->Head = NULL;
}

//β��
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
		printf("����ɹ���\n");
	}
	else
	{
		//������β�ڵ�
		ListNode *p = pl->Head;
		while (p->next != NULL)
			p = p->next;

		//����һ���½ڵ�
		ListNode *s = (ListNode *)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = value;
		s->next = NULL;

		//����β��
		p->next = s;
		printf("����ɹ���\n");
	}
}


//ͷ��
void ListPushFront(List * pl, ListType value)
{
	assert(pl != NULL);

	//����һ���½ڵ�
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	assert(p != NULL);
	p->data = value;
	p->next = NULL;

	// ����ͷ��
	p->next = pl->Head;
	pl->Head = p;
	printf("����ɹ���\n");
}

//βɾ
void ListPopBack(List * pl)
{
	assert(pl != NULL);
	if (pl->Head == NULL)
		printf("�����ѿգ��޷�ɾ����\n");
	else
	{
		ListNode * p = pl->Head;
		if (p->next == NULL)   //ֻ��һ���ڵ�ʱ
		{
			free(p);
			pl->Head = NULL;
			printf("ɾ���ɹ���\n");
		}
		else       //����ڵ�
		{
			while (p->next->next != NULL)
				p = p->next;
			free(p->next);
			p->next = NULL;
			printf("ɾ���ɹ���\n");
		}
	}
}

//ͷɾ
void ListPopFront(List * pl)
{
	assert(pl != NULL);
	if (pl->Head == NULL)
		printf("�����ѿգ��޷�ɾ����\n");
	else
	{
		ListNode * p = pl->Head;
		pl->Head = p->next;
		free(p);
		printf("ɾ���ɹ���\n");
	}
}

//����
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

//չʾ���Ա�
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

//����ط�����
void ListInsert(List * pl, size_t index, ListType value)
{
	assert(pl != NULL);
	ListNode * p = pl->Head;
	if (index == 1)       //����һ��λ�ò���
	{
		ListNode * s = (ListNode *)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = value;
		s->next = NULL;

		s->next = pl->Head;
		pl->Head = s;
		printf("����ɹ���\n");
	}
	else
	{
		int count = 2; //��ʶλ��
		while (p != NULL)
		{
			if (count == index)   //�ҵ���
			{
				ListNode * s = (ListNode *)malloc(sizeof(ListNode));
				assert(s != NULL);
				s->data = value;
				s->next = NULL;

				s->next = p->next;
				p->next = s;
				printf("����ɹ���\n");
				break;
			}
			p = p->next;
			count++;
		}
		if (p == NULL)  //û�ҵ�
			printf("λ�ò����ʣ��޷����룡\n");
	}
}


//����ط�ɾ��
void ListErase(List * pl, size_t index)
{
	assert(pl != NULL);
	if (pl->Head == NULL)
		printf("�����ѿգ��޷�ɾ����\n");
	else
	{
		ListNode * p = pl->Head;
		if (index == 1)  //ɾ����һ��λ��
		{
			pl->Head = p->next;
			free(p);
			printf("ɾ���ɹ���\n");
		}
		else
		{
			int count = 2, flag = 0; //flag���ڱ�ʶ��ѭ������ʱ��û���ҵ�
			while (p->next != NULL)
			{
				if (count == index)
				{
					ListNode * s = p->next;
					p->next = s->next;
					free(s);
					printf("ɾ���ɹ���\n");
					flag = 1;
					break;
				}
				p = p->next;
				count++;
			}
			if (flag == 0) //���� p==NULL ����Ϊɾ���һ��ʱ����pҲΪNULL
				printf("λ�ò����ʣ��޷�ɾ����\n");
		}
	}
}


//��ֵɾ��
void ListRemove(List * pl, ListType value)
{
	assert(pl != NULL);
	if (pl->Head == NULL)
	{
		printf("����Ϊ�գ��޷�ɾ����\n");
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
	printf("ɾ���ɹ���\n");
}


//�޸�
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
			printf("�޸ĳɹ���\n");
			break;
		}
		p = p->next;
		count++;
	}
	if (p == NULL)
		printf("λ�ò����ʣ��޷��޸ģ�\n");
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


//��ʼ��������
void ListInit(List * pl)
{
	(*pl) = (ListNode *)malloc(sizeof(ListNode));
	assert(*pl != NULL);
	(*pl)->data = 2020;
	(*pl)->next = NULL;
}

//β�巨����
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

//ͷ�巨����
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

//չʾ���Ա�
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





/*����ͷ��� 

//��ʼ��������
void ListInit(List * pl)
{ //�����List���ͱ�������ListNode��ָ�����ͣ�plΪָ��Listָ���ָ�룬Ϊ����ָ��
	(*pl) = NULL;
}

//β�巨����
void ListCreate_Tail(List * pl)
{
	//�Ƚ�����һ���ڵ�
	*pl = (ListNode *)malloc(sizeof(ListNode));
	assert(*pl != NULL);
	(*pl)->data = 1;
	(*pl)->next = NULL;

	//����һ���ָ��pָ���һ���ڵ�
	ListNode * p = *pl;
	for (int i = 2; i <= 10; i++)
	{
		//�½�һ���ڵ㣬������һ���ָ��sָ����
		ListNode * s = (ListNode *)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;

		//��s���ӵ�������
		p->next = s;

		//��pָ��sҲ�����������һ���ڵ�׼����һ��ѭ��
		p = s;
	}

}

//ͷ�巨����
void ListCreate_Head(List * pl)
{
	for (int i = 1; i <= 10; i++)
	{
		//�½�һ���ڵ㣬������һ���ָ��pָ����
		ListNode * p = (ListNode *)malloc(sizeof(ListNode));
		assert(p != NULL);
		p->data = i;
		p->next = NULL;

		//��pͷ�嵽������
		p->next = *pl;
		*pl = p;
	}
}

//չʾ���Ա�
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