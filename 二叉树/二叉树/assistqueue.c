#define _CRT_SECURE_NO_WARNINGS 1


#include"assistqueue.h"

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
	while (plq->head != NULL)
	{
		LinkQueueNode *p = plq->head;
		plq->head = plq->head->link;
		free(p);
	}
}


//���
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


//����
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


//��ȡ��ͷԪ��
QNDataType LinkQueueHead(LinkQueue * plq)
{
	assert(plq != NULL);
	if (plq->head == NULL)
		return NULL;
	else
		return plq->head->data;
}

