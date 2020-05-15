#define _CRT_SECURE_NO_WARNINGS 1


#include"assiststack.h"


//栈的初始化
void StackInit(Stack* ps)
{
	assert(ps != NULL);
	ps->top = NULL;
}

//栈的销毁
void StackDestory(Stack* ps)
{
	assert(ps != NULL);
	while (ps->top != NULL)
	{
		StackNode *p = ps->top;
		ps->top = ps->top->link;
		free(p);
	}
}

//入栈
void StackPush(Stack* ps, SDataType x, char flag)
{
	assert(ps != NULL);
	StackNode *p = (StackNode *)malloc(sizeof(StackNode));
	assert(p != NULL);
	p->data = x;
	p->flag = flag;
	p->link = ps->top;
	ps->top = p;
}

//出栈
void StackPop(Stack* ps)
{
	assert(ps != NULL);
	if (ps->top == NULL)
		printf("栈空，无法出栈");
	else
	{
		StackNode *p = ps->top;
		ps->top = ps->top->link;
		free(p);
	}
}

//返回栈顶元素
SDataType StackTop(Stack* ps)
{
	assert(ps != NULL);
	if (ps->top == NULL)
		return NULL;
	else
		return ps->top->data;
}









