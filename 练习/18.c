class Solution
{
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL)
			return NULL;
		//添加头结点
		ListNode * p = (ListNode *)malloc(sizeof(ListNode));
		p->next = pHead;
		pHead = p;
		//删除
		while (p->next != NULL)
		{
			//在p->next不为NULL情况下，让s指向p->next
			ListNode * s = p->next;
			//count标记s是否有重复值
			int count = 0;
			//在s->next不为NULL且与s重复的情况下，删除s->next
			while (s->next != NULL && s->next->val == s->val)
			{
				count++;
				ListNode * w = s->next;
				s->next = w->next;
				free(w);
			}
			if (count)
			{
				p->next = s->next;
				free(s);
			}
			else
			{
				p = s;
			}
		}
		p = pHead;
		pHead = p->next;
		free(p);
		return pHead;
	}
};