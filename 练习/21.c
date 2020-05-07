struct ListNode *detectCycle(struct ListNode *head)
{
	struct ListNode * quick = head;
	struct ListNode * slow = head;
	while (quick != NULL && quick->next != NULL)
	{
		quick = quick->next->next;
		slow = slow->next;
		if (quick == slow)
			break;
	}
	if (quick == NULL || quick->next == NULL)
		return NULL;
	else
	{
		slow = head;
		while (1)
		{
			if (slow == quick)
				return quick;
			quick = quick->next;
			slow = slow->next;
		}
	}
}