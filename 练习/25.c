class Partition
{
public:
	ListNode* partition(ListNode* pHead, int x)
	{
		if (pHead == NULL)
			return NULL;
		ListNode * small = NULL, *s = NULL;
		ListNode * big = NULL, *b = NULL;
		while (pHead != NULL)
		{
			if (pHead->val <x)
			{
				if (small == NULL)
				{
					small = pHead;
					s = small;
					pHead = pHead->next;
				}
				else
				{
					s->next = pHead;
					s = s->next;
					pHead = pHead->next;
				}
			}
			else
			{
				if (big == NULL)
				{
					big = pHead;
					b = big;
					pHead = pHead->next;
				}
				else
				{
					b->next = pHead;
					b = b->next;
					pHead = pHead->next;
				}
			}
		}
		if (small == NULL)
			return big;
		else if (big == NULL)
			return small;
		else
		{
			s->next = big;
			b->next = NULL;
			return small;
		}
	}
};