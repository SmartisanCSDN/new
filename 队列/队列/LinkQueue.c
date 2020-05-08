#define _CRT_SECURE_NO_WARNINGS 1


#include"LinkQueue.h"




//��ʼ������
void LinkQueueInit(LinkQueue * plq)
{
	assert(plq != NULL);
	plq->head = NULL;
	plq->tail = NULL;
}


//�ݻ�����
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


//���
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


//����
void LinkQueuePop(LinkQueue * plq)
{
	assert(plq != NULL);
	if (plq->head == NULL)
		printf("�ӿ�\n");
	if (plq->head == plq->tail)
		plq->tail = NULL;
	LinkQueue *p = plq->head;
	plq->head = plq->head->link;
	free(p);
}

