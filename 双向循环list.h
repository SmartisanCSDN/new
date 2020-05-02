#ifndef _LIST_h_
#define _LIST_h_

#include"stdio.h"
#include"malloc.h"
#include"assert.h"


#define ListType int

typedef struct ListNode
{
	ListType data;
	struct ListNode * next;
}ListNode;

typedef struct List
{
	ListNode * Head;
}List;


void ListInit(List * pl); //初始化单链表
void ListPushBack(List * pl, ListType value); //尾插
void ListPushFront(List * pl, ListType value); //头插
void ListPopBack(List * pl); //尾删
void ListPopFront(List * pl); //头删
void ListShow(List pl);//展示线性表
size_t ListFind(List pl, ListType value); //查找
void ListInsert(List * pl, size_t index, ListType value); //任意地方插入
void ListErase(List * pl, size_t index); //任意地方删除
void ListRemove(List * pl, ListType value); //按值删除
void ListModify(List *pl, size_t index, ListType value); //修改

/*
//定义链表节点类型
typedef struct ListNode
{
	ListType data;
	struct ListNode * next;
}ListNode;


//链表类型，一个链表就是指向一个节点的指针
typedef ListNode* List;

void text(); //测试程序
void ListInit(List * pl);  //初始化单链表
void ListCreate_Tail(List * pl);  //尾插法建表
void ListCreate_Head(List * p);  //头插法建表
void ListShow(); //展示线性表

*/
#endif