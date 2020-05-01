#ifndef _LIST_H_
#define _LIST_H_


#include<stdio.h>
#include<assert.h>

#define ListType int

typedef struct ListNode
{
	ListType data;
	struct ListNode * prev;
	struct ListNode * next;

}ListNode;

typedef struct List
{
	ListType * Head;
}List;





#endif