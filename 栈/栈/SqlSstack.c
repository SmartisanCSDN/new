#define _CRT_SECURE_NO_WARNINGS 1


#include"SqlStack.h"


//ջ�ĳ�ʼ��
void StackInit(Stack* ps)
{
	assert(ps != NULL);
	ps->capacity = INITCAPACITY;
	ps->data = (DataType *)malloc(sizeof(DataType) * ps->capacity);
	assert(ps->data != NULL);
	for (int i = 0; i < ps->capacity; i++)
		ps->data[i] = 0;
	ps->top = 0;
}

//ջ������
void StackDestory(Stack* ps)
{
	assert(ps != NULL);
	free(ps->data);
	free(ps);
	ps = NULL;
}


//��ջ
void StackPush(Stack* ps, DataType x)
{
	assert(ps != NULL);
	if (ps->top == ps->capacity)
	{
		ps->data = realloc(ps->data, sizeof(DataType) * ps->capacity * 2);
		assert(ps->data != NULL);
		ps->capacity *= 2;
	}
	ps->data[ps->top] = x;
	ps->top++;
}

//��ջ
void StackPop(Stack* ps)
{
	assert(ps != NULL);
	if (ps->top == 0)
		printf("ջ�գ�\n");
	else
	{
		ps->top--;
		ps->data[ps->top] = 0;
	}
}

//����ջ��Ԫ��
DataType StackTop(Stack* ps)
{
	assert(ps != NULL);
	if (ps->top = 0)
	{
		printf("ջ�գ�\n");
		return (DataType)0;
	}
	else
	{
		return ps->data[ps->top - 1];
	}
}


