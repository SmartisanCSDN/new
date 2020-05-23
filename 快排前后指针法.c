//一趟快速排序-前后指针法
int OnceQuickSort_fb(int* value, int start, int end)
{
	int mid = (start + end) / 2;
	if (value[start] > value[end])
	{
		int temp = value[start];
		value[start] = value[end];
		value[end] = temp;
	}
	if (value[start] > value[mid])
	{
		int temp = value[start];
		value[start] = value[mid];
		value[mid] = temp;
	}
	if (value[mid] > value[end])
	{
		int temp = value[mid];
		value[mid] = value[end];
		value[end] = temp;
	}
	{
		int temp = value[start];
		value[start] = value[mid];
		value[mid] = temp;
	}
	int temp = value[start];
	int front = start + 1, back = start;
	while (front <= end && value[front] < temp)
	{
		front++;
		back++;
	}
	while (front <= end)
	{
		if (value[front] >= temp)
			front++;
		else
		{
			back++;
			int x = value[back];
			value[back] = value[front];
			value[front] = x;
			front++;
		}
	}
	value[start] = value[back];
	value[back] = temp;
	return back;
}