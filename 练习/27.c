class Solution
{
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
	{
		if (pListHead == NULL)
			return NULL;
		ListNode *p = pListHead;
		for (int i = 0; i < k; i++)
		{
			if (p == NULL)
				return NULL;
			else
				p = p->next;
		}
		while (p != NULL)
		{
			p = p->next;
			pListHead = pListHead->next;
		}
		return pListHead;
	}
};