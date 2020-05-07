SListNode* BuySListNode(SLTDateType x)
{
	SListNode *p = (SListNode *)malloc(sizeof(SListNode));
	assert(p != NULL);
	p->data = x;
	p->next = NULL;
}


void SListPrint(SListNode* plist)
{
	SListNode *p = plist;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("Over.");
}


void SListPushBack(SListNode** pplist, SLTDateType x)
{
	assert(pplist != NULL);
	if (*pplist = NULL)
	{
		SListNode *p = BuySListNode(x);
		*pplist = p;
	}
	else
	{
		SListNode *p = *pplist;
		while (p->next != NULL)
			p = p->next;
		SListNode *s = BuySListNode(x);
		p->next = s;
	}
}


void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist != NULL);
	SListNode *p = BuySListNode(x);
	p->next = *pplist;
	*pplist = p;
}


void SListPopBack(SListNode** pplist)
{
	assert(pplist != NULL);
	if (*pplist == NULL)
		printf("链表已空，无法删除！");
	else
	{
		if ((*pplist)->next = NULL)
		{
			free(*pplist);
			*pplist = NULL;
		}
		else
		{
			SListNode *p = *pplist;
			while (p->next->next != NULL)
				p = p->next;
			free(p->next);
			p->next = NULL;
		}
	}
}


void SListPopFront(SListNode** pplist)
{
	assert(pplist != NULL);
	if (*pplist == NULL)
		printf("链表已空，无法删除！");
	else
	{
		SListNode *p = *pplist;
		*pplist = p->next;
		free(p);
	}
}


SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	SListNode *p = plist;
	while (p != NULL)
	{
		if (p->data == x)
			return p;
	}
	return NULL;
}


void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos != NULL);
	SListNode *p = BuySListNode(x);
	p->next = pos->next;
	pos->next = p;
}


void SListEraseAfter(SListNode* pos)
{
	assert(pos != NULL);
	if (pos->next == NULL)
		printf("无法删除！");
	else
	{
		SListNode *p = pos->next;
		pos->next = pos->next->next;
		free(p);
	}
}


void SListDestory(SListNode* plist)
{
	if (plist == NULL)
		return plist;
	SListNode *p = plist;
	while (p != NULL)
	{
		SListNode *s = p->next;
		free(p);
		p = s;
	}
	plist = NULL;
}