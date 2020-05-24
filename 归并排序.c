//πÈ≤¢≈≈–Ú
void MergeSort(int* value, int start, int end)
{
	assert(value != NULL);
	if (start < end)
	{
		int* fuzhu = (int*)malloc(sizeof(int)* (end - start + 1));
		Merge(value, fuzhu, start, end);
	}
}

void Merge(int* value, int* fuzhu, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		Merge(value, fuzhu, start, mid);
		Merge(value, fuzhu, mid + 1, end);
		int begin1 = start, begin2 = mid + 1, i = 0;
		while (begin1 <= mid && begin2 <= end)
		{
			if (value[begin1] < value[begin2])
			{
				fuzhu[i++] = value[begin1];
				begin1++;
			}
			else
			{
				fuzhu[i++] = value[begin2];
				begin2++;
			}
		}
		while (begin1 <= mid)
		{
			fuzhu[i++] = value[begin1];
			begin1++;
		}
		while (begin2 <= end)
		{
			fuzhu[i++] = value[begin2];
			begin2++;
		}
		for (i = 0; i <= end - start; i++)
			value[i + start] = fuzhu[i];
	}
}