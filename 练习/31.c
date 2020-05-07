ListNode * ByeNode(LTDataType x)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	assert(p != NULL);
	p->data = x;
	p->next = p;
	p->prev = p;
	return p;
}

ListNode* ListCreate()
{
	ListNode *pHead = ByeNode(0);
	return pHead;
}


void ListDestory(ListNode* pHead)
{
	assert(pHead != NULL);
	while (pHead->next != pHead)
	{
		ListNode *p = pHead->next;
		pHead->next = p->next;
		free(p);
	}
	free(pHead);
	pHead = NULL;
}


void ListPrint(ListNode* pHead)
{
	assert(pHead != NULL);
	ListNode *p = pHead->next;
	while (p != pHead)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("Over.\n");
}


void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead != NULL);
	ListNode *p = ByeNode(x);
	p->next = pHead;
	p->prev = pHead->prev;
	p->next->prev = p;
	p->prev->next = p;
}


void ListPopBack(ListNode* pHead)
{
	assert(pHead != NULL);
	if (pHead->prev == pHead)
		printf("链表已空，无法删除！");
	else
	{
		ListNode *p = pHead->prev;
		p->prev->next = p->next;
		p->next->prev = p->prev;
	}
}


void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead != NULL);
	ListNode *p = ByeNode(x);
	p->next = pHead->next;
	p->prev = pHead;
	p->prev->next = p;
	p->next->prev = p;
}


void ListPopFront(ListNode* pHead)
{
	assert(pHead != NULL);
	if (pHead->prev == pHead)
		printf("链表已空，无法删除！");
	else
	{
		ListNode *p = pHead->next;
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
	}
}

ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead != NULL);
	ListNode *p = pHead->next;
	while (p != pHead)
	{
		if (p->data == x)
			return p;
	}
	return NULL;
}


void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos != NULL);
	ListNode *p = ByeNode(x);
	p->next = pos;
	p->prev = pos->prev;
	p->prev->next = p;
	p->next->prev = p;
}

void ListErase(ListNode* pos)
{
	assert(pos != NULL);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}
