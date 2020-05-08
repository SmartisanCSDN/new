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

//栈的初始化
void StackInit(LinkStack* ps);

//栈的销毁
void StackDestory(LinkStack* ps);

//入栈
void StackPush(LinkStack* ps, DataType x);

//出栈
void StackPop(LinkStack* ps);

//返回栈顶元素
DataType StackTop(LinkStack* ps);


#endif