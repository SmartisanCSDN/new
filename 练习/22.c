bool hasCycle(struct ListNode *head)
{
	struct ListNode * quick = head;
	struct ListNode * slow = head;
	while (quick != NULL && quick->next != NULL)
	{
		quick = quick->next->next;
		slow = slow->next;
		if (quick == slow)
			return true;
	}
	return false;
}