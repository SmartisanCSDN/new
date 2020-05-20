//∂˛¬∑≤Â»Î≈≈–Ú
void TwowayInsertSort(int* value, int start, int end)
{
	int len = (end - start + 1);
	int* fuzhu = (int*)malloc(sizeof(int)* len);
	fuzhu[0] = value[start];
	int head = 0, tail = 0;
	for (int i = start + 1; i <= end; i++)
	{
		if (value[i] < fuzhu[head])
		{
			head = (head - 1 + len) % len;
			fuzhu[head] = value[i];
		}
		else if (value[i] >= fuzhu[tail])
		{
			tail = tail + 1;
			fuzhu[tail] = value[i];
		}
		else
		{
			int j = ++tail;
			while (j != head && fuzhu[j - 1] > value[i])
			{
				fuzhu[j] = fuzhu[j - 1];
				j = (j - 1 + len) % len;
			}
			fuzhu[j] = value[i];
		}
	}
	for (int i = head; start <= end; i = (i + 1) % len)
		value[start++] = fuzhu[i];
	free(fuzhu);
}