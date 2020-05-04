struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
	if (headA == NULL || headB == NULL)
		return NULL;
	int flag1 = 0, flag2 = 0;
	ListNode * a = headA;
	ListNode * b = headB;
	while (a != b)
	{
		if (a != NULL && a->next == NULL)
		{
			a = headA;
			flag1++;
		}
		else
			a = a->next;
		if (b->next == NULL)
		{
			b = headA;
			flag2++;
		}
		else
			a = a->next;
		if (a == b)
			return a;
		if (flag1 == 2 || flag2 == 2)
			break;
	}
	return NULL;
}