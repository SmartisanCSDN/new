#define _CRT_SECURE_NO_WARNINGS 1


#include"LinkStack.h"


//栈的初始化
void StackInit(LinkStack* ps)
{
	assert(ps != NULL);
	ps->top = NULL;
}

//栈的销毁
void StackDestory(LinkStack* ps)
{
	assert(ps != NULL);
	while (ps->top != NULL)
	{
		LinkStackNode *p = ps->top;
		ps->top = ps->top->link;
		free(p);
	}
	free(ps);
}

//入栈
void StackPush(LinkStack* ps, DataType x)
{
	assert(ps != NULL);
	LinkStackNode *p = (LinkStackNode *)malloc(sizeof(LinkStackNode));
	assert(p != NULL);
	p->data = x;
	p->link = ps->top;
	ps->top = p;
}

//出栈
void StackPop(LinkStack* ps)
{
	assert(ps != NULL);
	if (ps->top == NULL)
		printf("栈空，无法出栈");
	else
	{
		LinkStackNode *p = ps->top;
		ps->top = ps->top->link;
		free(p);
	}
}

//返回栈顶元素
DataType StackTop(LinkStack* ps)
{
	assert(ps != NULL);
	if (ps->top == NULL)
		return -1;
	else
		return ps->top->data;
}









