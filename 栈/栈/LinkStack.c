#define _CRT_SECURE_NO_WARNINGS 1


#include"LinkStack.h"


//ջ�ĳ�ʼ��
void StackInit(LinkStack* ps)
{
	assert(ps != NULL);
	ps->top = NULL;
}

//ջ������
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

//��ջ
void StackPush(LinkStack* ps, DataType x)
{
	assert(ps != NULL);
	LinkStackNode *p = (LinkStackNode *)malloc(sizeof(LinkStackNode));
	assert(p != NULL);
	p->data = x;
	p->link = ps->top;
	ps->top = p;
}

//��ջ
void StackPop(LinkStack* ps)
{
	assert(ps != NULL);
	if (ps->top == NULL)
		printf("ջ�գ��޷���ջ");
	else
	{
		LinkStackNode *p = ps->top;
		ps->top = ps->top->link;
		free(p);
	}
}

//����ջ��Ԫ��
DataType StackTop(LinkStack* ps)
{
	assert(ps != NULL);
	if (ps->top == NULL)
		return -1;
	else
		return ps->top->data;
}









