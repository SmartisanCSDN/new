#ifndef _PHONEBOOK_H_
#define _PHONEBOOK_H_


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#define INITCAPACITY 3


//联系人信息
typedef struct persondata
{
	char* name;
	char* sex;
	char* tele;
	char* addr;
}persondata;
//联系人链的节点
typedef struct personnode
{
	persondata *data;
	struct personnode *next;
}personnode;
//电话本，包含一个指向联系人链的头结点
typedef struct pb
{
	personnode *personlist;
}pb;



//初始化电话本
void pbInit(pb *ppb);

//添加联系人
void pbPush(pb *ppb, persondata *pperson);

//删除联系人
int pbPop(pb *ppb, char *name);

//查找指定联系人
personnode* pbFind(pb *ppb, char *name);

//修改指定联系人
int pbModify(pb *ppb, char *name);

//显示所有联系人信息
void pbShow(pb *ppb);

//清空所有联系人
void pbDistory(pb *ppb);

//以名字排序所有联系人
void pbSort(pb *ppb);
void pbSort_dg(personnode *pnode);
void insertSort(personnode *pnode);




#endif //_PHONEBOOK_H_