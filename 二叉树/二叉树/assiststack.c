#define _CRT_SECURE_NO_WARNINGS 1


#include"assiststack.h"


//ջ�ĳ�ʼ��
void StackInit(Stack* ps)
{
	assert(ps != NULL);
	ps->top = NULL;
}

//ջ������
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

//��ջ
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

//��ջ
void StackPop(Stack* ps)
{
	assert(ps != NULL);
	if (ps->top == NULL)
		printf("ջ�գ��޷���ջ");
	else
	{
		StackNode *p = ps->top;
		ps->top = ps->top->link;
		free(p);
	}
}

//����ջ��Ԫ��
SDataType StackTop(Stack* ps)
{
	assert(ps != NULL);
	if (ps->top == NULL)
		return NULL;
	else
		return ps->top->data;
}









