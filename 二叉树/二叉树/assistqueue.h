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


//��ʼ������
void LinkQueueInit(LinkQueue * plq);

//�ݻ�����
void LinkQueueDestory(LinkQueue * plq);

//���
void LinkQueuePush(LinkQueue * plq, QNDataType x);

//����
void LinkQueuePop(LinkQueue * plq);

//��ȡ��ͷԪ��
QNDataType LinkQueueHead(LinkQueue * plq);



#endif //_ASSISTQUEUE_H_