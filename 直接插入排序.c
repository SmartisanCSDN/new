//÷±Ω”≤Â»Î≈≈–Ú
void DirectInsertSort(int* value, int start, int end)
{
	assert(value != NULL);
	for (int i = start + 1; i <= end; i++)
	{
		int temp = value[i];
		int index = i;
		while (index > start && value[index - 1] > temp)
		{
			value[index] = value[index - 1];
			index--;
		}
		value[index] = temp;
	}
}