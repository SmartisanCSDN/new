//¿ìÅÅ·Çµİ¹é
void QuickSort_N(int* value, int start, int end)
{
	assert(value != NULL);
	Stack st;
	StackInit(&st);
	if (start < end)
	{
		StackPush(&st, start);
		StackPush(&st, end);
	}
	while (st.top != NULL)
	{
		int right = StackTop(&st);
		StackPop(&st);
		int left = StackTop(&st);
		StackPop(&st);
		int index = OnceQuickSort(value, left, right);
		if (left < index - 1)
		{
			StackPush(&st, left);
			StackPush(&st, index - 1);
		}
		if (index + 1 < right)
		{
			StackPush(&st, index + 1);
			StackPush(&st, right);
		}
	}
}