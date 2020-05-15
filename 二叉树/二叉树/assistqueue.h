#ifndef _ASSISTQUEUE_H_
#define _ASSISTQUEUE_H_


#include"common.h"
#include"tree.h"

typedef TreeNode* QNDataType;

typedef struct LinkQueueNode
{
	QNDataType data;
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
void LinkQueuePush(LinkQueue * plq, QNDataType x);

//出队
void LinkQueuePop(LinkQueue * plq);

//获取对头元素
QNDataType LinkQueueHead(LinkQueue * plq);



#endif //_ASSISTQUEUE_H_