//ц╟ещеепР
void BubbleSort(int* value, int start, int end)
{
	assert(value != NULL);
	while (start < end)
	{
		int flag = 0;
		int temp = value[start];
		for (int i = start; i < end; i++)
		{
			if (value[i + 1] < temp)
			{
				value[i] = value[i + 1];
				flag++;
			}
			else
			{
				value[i] = temp;
				temp = value[i + 1];
			}
		}
		value[end] = temp;
		end--;
		if (!flag)
			break;
	}
}