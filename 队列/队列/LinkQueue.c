#define _CRT_SECURE_NO_WARNINGS 1


#include"LinkQueue.h"




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
	while (plq->head !=NULL)
	{
		LinkQueue *p = plq->head;
		plq->head = plq->head->link;
		free(p);
	}
	free(plq);
}


//入队
void LinkQueuePush(LinkQueue * plq, DataType x)
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
	if (plq->head == NULL)
		printf("队空\n");
	if (plq->head == plq->tail)
		plq->tail = NULL;
	LinkQueue *p = plq->head;
	plq->head = plq->head->link;
	free(p);
}

