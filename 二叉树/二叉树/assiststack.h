#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_


#include"common.h"
#include"tree.h"


typedef TreeNode* SDataType;

typedef struct StackNode
{
	SDataType data;
	char flag;
	struct StackNode * link;
}StackNode;


typedef struct Stack
{
	StackNode * top;
}Stack;

//栈的初始化
void StackInit(Stack* ps);

//栈的销毁
void StackDestory(Stack* ps);

//入栈
void StackPush(Stack* ps, SDataType x, char flag);

//出栈
void StackPop(Stack* ps);

//返回栈顶元素
SDataType StackTop(Stack* ps);


#endif