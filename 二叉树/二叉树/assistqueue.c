#define _CRT_SECURE_NO_WARNINGS 1


#include"assistqueue.h"

//初始化链队
void LinkQueueInit(LinkQueue * plq)
{
	assert(plq != NULL);
	plq->head = NULL;
	plq->tail = NULL;
}


//摧毁链队
void LinkQueueDestory(LinkQueue * plq)
{
	assert(plq != NULL);
	while (plq->head != NULL)
	{
		LinkQueueNode *p = plq->head;
		plq->head = plq->head->link;
		free(p);
	}
}


//入队
void LinkQueuePush(LinkQueue * plq, QNDataType x)
{
	assert(plq != NULL);
	LinkQueueNode *p = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	p->data = x;
	p->link = NULL;
	if (plq->head == NULL)
	{
		plq->head = p;
		plq->tail = p;
	}
	else
	{
		plq->tail->link = p;
		plq->tail = p;
	}
}


//出队
void LinkQueuePop(LinkQueue * plq)
{
	assert(plq != NULL);
	if (plq->head != NULL)
	{
		if (plq->head == plq->tail)
		{
			plq->tail = NULL;
		}
		LinkQueueNode *p = plq->head;
		plq->head = plq->head->link;
		free(p);
	}
}


//获取对头元素
QNDataType LinkQueueHead(LinkQueue * plq)
{
	assert(plq != NULL);
	if (plq->head == NULL)
		return NULL;
	else
		return plq->head->data;
}

