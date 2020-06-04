#define _CRT_SECURE_NO_WARNINGS 1


#include"phonebook.h"



//��ʼ���绰��
void pbInit(pb *ppb)
{
	assert(ppb != NULL);
	//Ϊ�绰����ϵ����ͷ��㿪�ٿռ�
	ppb->personlist = (personnode*)malloc(sizeof(personnode));
	//��ʼ��ͷ���
	ppb->personlist->data = NULL;
	ppb->personlist->next = NULL;
}

//�����ϵ��
void pbPush(pb *ppb, persondata *pperson)
{
	assert(ppb != NULL && pperson != NULL);
	//����һ���½ڵ�
	personnode *pnode = (personnode*)malloc(sizeof(personnode));
	assert(pnode != NULL);
	//Ϊ�½ڵ㿪��data�ռ�
	pnode->data = (persondata*)malloc(sizeof(persondata));
	assert(pnode->data != NULL);
	//����ϵ����Ϣ�������˽ڵ�
	strcpy(pnode->data->name, pperson->name);
	strcpy(pnode->data->sex, pperson->sex);
	strcpy(pnode->data->tele, pperson->tele);
	strcpy(pnode->data->addr, pperson->addr);
	//���˽ڵ������绰��
	pnode->next = ppb->personlist->next;
	ppb->personlist->next = pnode;
}

//ɾ����ϵ��
int pbPop(pb *ppb, char *name)
{
	assert(ppb != NULL);
	//���ò��Һ����ҵ�Ҫɾ������ϵ�˽ڵ�
	personnode *pnode = pbFind(ppb, name);
	//û�ҵ��ͷ���-1
	if (pnode == NULL)
	{
		return -1;
	}
	//�ҵ�Ҫɾ�����ǰ��
	personnode *pprev = ppb->personlist;
	while (pprev != NULL && pprev->next != pnode)
		pprev = pprev->next;
	//ɾ��
	pprev->next = pnode->next;
	free(pnode->data); //��Ҫ�����ͷŽڵ�������
	free(pnode);
	return 1;
}

//����ָ����ϵ��
personnode* pbFind(pb *ppb, char *name)
{
	assert(ppb != NULL);
	personnode *pnode = ppb->personlist->next;
	while (pnode != NULL && strcmp(pnode->data->name, name) != 0)
		pnode = pnode->next;
	return pnode;
}

//�޸�ָ����ϵ��
int pbModify(pb *ppb, char *name)
{
	assert(ppb != NULL);
	//����Ҫ�޸ĵ���ϵ�ˣ��Ҳ�������-1
	personnode *pnode = pbFind(ppb, name);
	if (pnode == NULL)
		return -1;
	//ȷ��Ҫ�޸ĵ���Ŀ
	printf("please choose data of modify\n");
	int choose = 0;
	while (1)
	{
		printf("[1]name [2]sex [3]telephone [4]address\n");
		scanf("%d", &choose);
		if (choose >= 1 && choose <= 4)
			break;
		else
			printf("error, please choose again!!!\n");
	}
	//��ȡ�޸ĺ������
	printf("please input data:");
	char *data = NULL;
	scanf("%s", data);
	//����Ҫ�޸ĵ���Ŀ�޸���Ӧ��
	switch (choose)
	{
	case 1:
		strcpy(pnode->data->name, data);
	case 2:
		strcpy(pnode->data->sex, data);
	case 3:
		strcpy(pnode->data->tele, data);
	case 4:
		strcpy(pnode->data->addr, data);
	}
	return 1;
}

//��ʾ������ϵ����Ϣ
void pbShow(pb *ppb)
{
	assert(ppb != NULL);
	personnode *pnode = ppb->personlist->next;
	while (pnode != NULL)
	{
		printf("%c\t%c\t%c\t%c\n", pnode->data->name, pnode->data->sex, pnode->data->tele, pnode->data->addr);
		pnode = pnode->next;
	}
}

//���������ϵ��
void pbDistory(pb *ppb)
{
	assert(ppb != NULL);
	while (ppb->personlist->next != NULL)
	{
		personnode * pnode = ppb->personlist->next;
		ppb->personlist->next = pnode->next;
		free(pnode->data);
		free(pnode);
	}
}

//����������������ϵ��
void pbSort(pb *ppb)
{
	pbSort_dg(ppb->personlist->next);
}
void pbSort_dg(personnode *pnode)
{
	if (pnode == NULL || pnode->next == NULL)
		return;
	pbSort_dg(pnode->next);
	insertSort(pnode);
}
void insertSort(personnode *pnode)
{
	persondata *pdata = pnode->data;
	while (pnode->next != NULL && strcmp(pnode->data->name, pnode->next->data->name) > 0)
	{
		pnode->data = pnode->next->data;
		pnode = pnode->next;
	}
	pnode->data = pdata;
}

