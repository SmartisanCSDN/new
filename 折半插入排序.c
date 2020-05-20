//’€∞Î≤Â»Î≈≈–Ú
void HalfInsertSort(int* value, int start, int end)
{
	assert(value != NULL);
	for (int i = start + 1; i <= end; i++)
	{
		int temp = value[i];
		int low = start, high = i - 1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (value[mid] > temp)
				high = mid - 1;
			else
				low = mid + 1;
		}
		for (int j = i; j > low; j--)
			value[j] = value[j - 1];
		value[low] = temp;
	}
}