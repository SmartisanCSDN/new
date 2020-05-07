struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL)
		return head;
	else
	{
		struct ListNode * p = head->next;
		head->next = NULL;
		while (p != NULL)
		{
			struct ListNode * s = p->next;
			p->next = head;
			head = p;
			p = s;
		}
		return head;
	}
}