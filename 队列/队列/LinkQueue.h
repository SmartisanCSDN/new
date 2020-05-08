#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_

#include<stdio.h>
#include<assert.h>


typedef int DataType;

typedef struct LinkQueueNode
{
	DataType data;
	struct LinkQueueNode * link;
}LinkQueueNode;

typedef struct LinkQueue
{
	LinkQueueNode * head;
	LinkQueueNode * tail;
}LinkQueue;


//��ʼ������
void LinkQueueInit(LinkQueue * plq);

//�ݻ�����
void LinkQueueDestory(LinkQueue * plq);

//���
void LinkQueuePush(LinkQueue * plq);

//����
void LinkQueuePop(LinkQueue * plq);




#endif //_LINKQUEUE_H_