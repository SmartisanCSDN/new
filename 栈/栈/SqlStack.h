#ifndef _SQLSTACK_H_
#define _SQLSTACK_H_



#include"stdio.h"
#include"stdlib.h"
#include"assert.h"



#define INITCAPACITY 10;

typedef int DataType; //ջ����������


typedef struct Stack
{
	DataType *data;
	int top;  //ջ��
	int capacity;  //����
}Stack;



//ջ�ĳ�ʼ��
void StackInit(Stack* ps);

//ջ������
void StackDestory(Stack* ps);

//��ջ
void StackPush(Stack* ps, DataType x);

//��ջ
void StackPop(Stack* ps);

//����ջ��Ԫ��
DataType StackTop(Stack* ps);



#endif