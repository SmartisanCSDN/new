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


//初始化链队
void LinkQueueInit(LinkQueue * plq);

//摧毁链队
void LinkQueueDestory(LinkQueue * plq);

//入队
void LinkQueuePush(LinkQueue * plq);

//出队
void LinkQueuePop(LinkQueue * plq);




#endif //_LINKQUEUE_H_