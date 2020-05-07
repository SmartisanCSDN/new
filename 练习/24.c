class PalindromeList {
public:
	bool chkPalindrome(ListNode* A)
	{
		if (A == NULL)
			return false;
		if (A->next == NULL)
			return true;
		//快慢指针找中点
		ListNode *quick = A;
		ListNode *slow = A;
		while (quick != NULL && quick->next != NULL)
		{
			quick = quick->next->next;
			slow = slow->next;
		}
		//反转链表后半部分
		if (slow->next != NULL)
		{
			ListNode * p = slow->next;
			if (p->next == NULL)
			{
				p->next = slow;
				slow = p;
			}
			else
			{
				ListNode * s = p->next;
				while (s != NULL)
				{
					p->next = slow;
					slow = p;
					p = s;
					s = s->next;
				}
				p->next = slow;
				slow = p;
			}
		}
		//开始判断
		while (A != slow && A->next != slow)
		{
			if (A->val != slow->val)
				return false;
			else
			{
				A = A->next;
				slow = slow->next;
			}
		}
		if (A->next == slow && A->val != slow->val)
			return false;
		return true;
	}
};