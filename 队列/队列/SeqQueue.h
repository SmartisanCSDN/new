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


//初始化队列
void QueueInit(SeqQueue* pq);
//摧毁队列
void QueueDestory(SeqQueue* pq);
//入队
void QueuePush(SeqQueue* pq, DataType x);
//出队
void QueuePop(SeqQueue* pq);
//扩容函数
SeqQueue* rise(SeqQueue* pq);





#endif //_QUEUE_H_