struct ListNode* removeElements(struct ListNode* head, int val)
{
	if (head == NULL)
		return head;
	else
	{
		struct ListNode * p = head;
		while (p->next != NULL)
		{
			if (p->next->val == val)
			{
				struct ListNode * s = p->next;
				p->next = s->next;
				free(s);
			}
			else
				p = p->next;
		}
		p = head;
		if (p->val == val)
		{
			head = p->next;
			free(p);
		}
		return head;
	}
}