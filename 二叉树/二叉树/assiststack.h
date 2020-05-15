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

//ջ�ĳ�ʼ��
void StackInit(Stack* ps);

//ջ������
void StackDestory(Stack* ps);

//��ջ
void StackPush(Stack* ps, SDataType x, char flag);

//��ջ
void StackPop(Stack* ps);

//����ջ��Ԫ��
SDataType StackTop(Stack* ps);


#endif