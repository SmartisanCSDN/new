//一趟快速排序-挖坑法
int OnceQuickSort(int* value, int start, int end)
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
	while (start < end)
	{
		while (start < end)
		{
			if (value[end] < temp)
			{
				value[start] = value[end];
				start++;
				break;
			}
			else
				end--;
		}
		while (start < end)
		{
			if (value[start] > temp)
			{
				value[end] = value[start];
				end--;
				break;
			}
			else
				start++;
		}
	}
	value[start] = temp;
	return start;
}