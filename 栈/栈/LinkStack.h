#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_


#include<stdio.h>
#include<assert.h>

typedef int DataType;

typedef struct LinkStackNode
{
	DataType data;
	struct LinkStack * link;
}LinkStackNode;


typedef struct LinkStack
{
	LinkStackNode * top;
}LinkStack;

//ջ�ĳ�ʼ��
void StackInit(LinkStack* ps);

//ջ������
void StackDestory(LinkStack* ps);

//��ջ
void StackPush(LinkStack* ps, DataType x);

//��ջ
void StackPop(LinkStack* ps);

//����ջ��Ԫ��
DataType StackTop(LinkStack* ps);


#endif