#ifndef _PHONEBOOK_H_
#define _PHONEBOOK_H_


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#define INITCAPACITY 3


//��ϵ����Ϣ
typedef struct persondata
{
	char* name;
	char* sex;
	char* tele;
	char* addr;
}persondata;
//��ϵ�����Ľڵ�
typedef struct personnode
{
	persondata *data;
	struct personnode *next;
}personnode;
//�绰��������һ��ָ����ϵ������ͷ���
typedef struct pb
{
	personnode *personlist;
}pb;



//��ʼ���绰��
void pbInit(pb *ppb);

//�����ϵ��
void pbPush(pb *ppb, persondata *pperson);

//ɾ����ϵ��
int pbPop(pb *ppb, char *name);

//����ָ����ϵ��
personnode* pbFind(pb *ppb, char *name);

//�޸�ָ����ϵ��
int pbModify(pb *ppb, char *name);

//��ʾ������ϵ����Ϣ
void pbShow(pb *ppb);

//���������ϵ��
void pbDistory(pb *ppb);

//����������������ϵ��
void pbSort(pb *ppb);
void pbSort_dg(personnode *pnode);
void insertSort(personnode *pnode);




#endif //_PHONEBOOK_H_