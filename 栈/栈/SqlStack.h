#ifndef _SQLSTACK_H_
#define _SQLSTACK_H_



#include"stdio.h"
#include"stdlib.h"
#include"assert.h"



#define INITCAPACITY 10;

typedef int DataType; //栈中数据类型


typedef struct Stack
{
	DataType *data;
	int top;  //栈顶
	int capacity;  //容量
}Stack;



//栈的初始化
void StackInit(Stack* ps);

//栈的销毁
void StackDestory(Stack* ps);

//入栈
void StackPush(Stack* ps, DataType x);

//出栈
void StackPop(Stack* ps);

//返回栈顶元素
DataType StackTop(Stack* ps);



#endif