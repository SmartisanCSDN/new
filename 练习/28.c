struct ListNode* middleNode(struct ListNode* head)
{
	struct ListNode *p = head, *s = head;
	while (s != NULL && s->next != NULL)
	{
		p = p->next;
		s = s->next->next;
	}
	return p;
}