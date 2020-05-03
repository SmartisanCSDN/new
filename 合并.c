struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	ListNode *s = p;
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->val < l2->val)
		{
			s->next = l1;
			l1 = l1->next;
			s = s->next;
			s->next = NULL;
		}
		else
		{
			s->next = l2;
			l2 = l2->next;
			s = s->next;
			s->next = NULL;
		}
	}
	if (l1 != NULL)
		s->next = l1;
	if (l2 != NULL)
		s->next = l2;
	s = p;
	p = p->next;
	free(s);
	return p;
}