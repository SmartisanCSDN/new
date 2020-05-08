#define _CRT_SECURE_NO_WARNINGS 1


#include"SeqQueue.h"


//��ʼ������
void QueueInit(SeqQueue* pq)
{
	assert(pq != NULL);
	pq->capacity = QueueInitCapacity;
	pq->capacity_t = pq->capacity + 1;
	pq->data = (DataType *)malloc(sizeof(DataType)* pq->capacity_t);
	assert(pq->data != NULL);
	pq->head = 0;
	pq->tail = 0;
}

//�ݻٶ���
void QueueDestory(SeqQueue* pq)
{
	assert(pq != NULL);
	free(pq->data);
	free(pq);
}
//���
void QueuePush(SeqQueue* pq, DataType x)
{
	assert(pq != NULL);
	if ((pq->tail + 1) % pq->capacity == pq->head)
		rise(pq);
	pq->tail = x;
	pq->tail = (pq->tail + 1) % pq->capacity;
}
//����
void QueuePop(SeqQueue* pq)
{
	assert(pq != NULL);
	if (pq->head == pq->tail)
		printf("�ӿ�\n");
	else
	{
		pq->head = 0;
		pq->head++;
	}
}

//���ݺ���
void rise(SeqQueue* pq)
{
	DataType *newdata = (DataType *)malloc(sizeof(DataType) * pq->capacity * 2 + 1);
	if (pq->tail > pq->head)
	{
		memcpy(newdata, pq->data + pq->head, sizeof(DataType) * (pq->tail - pq->head));
		pq->data = newdata;
		pq->capacity_t += pq->capacity;
		pq->capacity *= 2;
		pq->tail -= pq->head;
		pq->head = 0;
	}
	if (pq->tail < pq->head)
	{
		memcpy(newdata, pq->data + pq->head, sizeof(DataType) * (pq->capacity_t - pq->head + 1));
		memcpy(newdata + pq->capacity_t - pq->head + 1, pq->data, sizeof(DataType) * (pq->tail - 1));
		pq->data = newdata;
		pq->head = 0;
		pq->tail = pq->capacity_t + pq->tail - pq->head + 1;
		pq->capacity_t += pq->capacity;
		pq->capacity *= 2;
	}
}


