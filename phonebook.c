#define _CRT_SECURE_NO_WARNINGS 1


#include"phonebook.h"



//初始化电话本
void pbInit(pb *ppb)
{
	assert(ppb != NULL);
	//为电话本联系人链头结点开辟空间
	ppb->personlist = (personnode*)malloc(sizeof(personnode));
	//初始化头结点
	ppb->personlist->data = NULL;
	ppb->personlist->next = NULL;
}

//添加联系人
void pbPush(pb *ppb, persondata *pperson)
{
	assert(ppb != NULL && pperson != NULL);
	//申请一个新节点
	personnode *pnode = (personnode*)malloc(sizeof(personnode));
	assert(pnode != NULL);
	//为新节点开辟data空间
	pnode->data = (persondata*)malloc(sizeof(persondata));
	assert(pnode->data != NULL);
	//将联系人信息拷贝到此节点
	strcpy(pnode->data->name, pperson->name);
	strcpy(pnode->data->sex, pperson->sex);
	strcpy(pnode->data->tele, pperson->tele);
	strcpy(pnode->data->addr, pperson->addr);
	//将此节点链到电话本
	pnode->next = ppb->personlist->next;
	ppb->personlist->next = pnode;
}

//删除联系人
int pbPop(pb *ppb, char *name)
{
	assert(ppb != NULL);
	//调用查找函数找到要删除的联系人节点
	personnode *pnode = pbFind(ppb, name);
	//没找到就返回-1
	if (pnode == NULL)
	{
		return -1;
	}
	//找到要删除点的前驱
	personnode *pprev = ppb->personlist;
	while (pprev != NULL && pprev->next != pnode)
		pprev = pprev->next;
	//删除
	pprev->next = pnode->next;
	free(pnode->data); //不要忘记释放节点中数据
	free(pnode);
	return 1;
}

//查找指定联系人
personnode* pbFind(pb *ppb, char *name)
{
	assert(ppb != NULL);
	personnode *pnode = ppb->personlist->next;
	while (pnode != NULL && strcmp(pnode->data->name, name) != 0)
		pnode = pnode->next;
	return pnode;
}

//修改指定联系人
int pbModify(pb *ppb, char *name)
{
	assert(ppb != NULL);
	//查找要修改的联系人，找不到返回-1
	personnode *pnode = pbFind(ppb, name);
	if (pnode == NULL)
		return -1;
	//确定要修改的项目
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
	//获取修改后的数据
	printf("please input data:");
	char *data = NULL;
	scanf("%s", data);
	//根据要修改的项目修改相应项
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

//显示所有联系人信息
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

//清空所有联系人
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

//以名字排序所有联系人
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

