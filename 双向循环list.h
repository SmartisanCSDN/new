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


void ListInit(List * pl); //��ʼ��������
void ListPushBack(List * pl, ListType value); //β��
void ListPushFront(List * pl, ListType value); //ͷ��
void ListPopBack(List * pl); //βɾ
void ListPopFront(List * pl); //ͷɾ
void ListShow(List pl);//չʾ���Ա�
size_t ListFind(List pl, ListType value); //����
void ListInsert(List * pl, size_t index, ListType value); //����ط�����
void ListErase(List * pl, size_t index); //����ط�ɾ��
void ListRemove(List * pl, ListType value); //��ֵɾ��
void ListModify(List *pl, size_t index, ListType value); //�޸�

/*
//��������ڵ�����
typedef struct ListNode
{
	ListType data;
	struct ListNode * next;
}ListNode;


//�������ͣ�һ���������ָ��һ���ڵ��ָ��
typedef ListNode* List;

void text(); //���Գ���
void ListInit(List * pl);  //��ʼ��������
void ListCreate_Tail(List * pl);  //β�巨����
void ListCreate_Head(List * p);  //ͷ�巨����
void ListShow(); //չʾ���Ա�

*/
#endif