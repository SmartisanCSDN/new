struct Node* copyRandomList(struct Node* head)
{
	if (head == NULL)
		return NULL;
	ListNode* oldp = head;
	ListNode* newp = NULL;
	while (oldp != NULL)
	{
		newp = (ListNode*)malloc(sizeof(ListNode));
		newp->val = oldp->val;
		newp->random = NULL;
		newp->next = oldp->next;
		oldp->next = newp;
		oldp = newp->next;
	}
	oldp = head;
	newp = oldp->next;
	while (oldp != NULL)
	{
		if (oldp->random != NULL)
			newp->random = oldp->random->next;
		oldp = newp->next;
		if (oldp == NULL)
			break;
		newp = oldp->next;
	}
	ListNode* newhead = head->next;
	oldp = head;
	newp = oldp->next;
	while (oldp != NULL)
	{
		oldp->next = newp->next;
		oldp = oldp->next;
		if (oldp == NULL)
		{
			newp->next = NULL;
			break;
		}
		newp->next = oldp->next;
		newp = newp->next;
	}
	return newhead;
}