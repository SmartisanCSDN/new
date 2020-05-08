#ifndef _QUEUE_H_
#define _QUEUE_H_

#include<stdio.h>
#include<assert.h>
#include<string.h>

#define QueueInitCapacity 10;

typedef int DataType;

typedef struct SeqQueue
{
	DataType *data;
	int head;
	int tail;
	int capacity;
	int capacity_t;
}SeqQueue;


//��ʼ������
void QueueInit(SeqQueue* pq);
//�ݻٶ���
void QueueDestory(SeqQueue* pq);
//���
void QueuePush(SeqQueue* pq, DataType x);
//����
void QueuePop(SeqQueue* pq);
//���ݺ���
SeqQueue* rise(SeqQueue* pq);





#endif //_QUEUE_H_