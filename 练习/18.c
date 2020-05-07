class Solution
{
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL)
			return NULL;
		//���ͷ���
		ListNode * p = (ListNode *)malloc(sizeof(ListNode));
		p->next = pHead;
		pHead = p;
		//ɾ��
		while (p->next != NULL)
		{
			//��p->next��ΪNULL����£���sָ��p->next
			ListNode * s = p->next;
			//count���s�Ƿ����ظ�ֵ
			int count = 0;
			//��s->next��ΪNULL����s�ظ�������£�ɾ��s->next
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