//÷±Ω”—°‘Ò≈≈–Ú
void DirectChooseSort(int* value, int start, int end)
{
	assert(value != NULL);
	for (int i = start; i < end; i++)
	{
		int choose = i;
		for (int j = i + 1; j <= end; j++)
		{
			if (value[j] < value[choose])
				choose = j;
		}
		int temp = value[i];
		value[i] = value[choose];
		value[choose] = temp;
	}
}