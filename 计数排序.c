///////////////��������////////////////
void CarSort(int* value, int start, int end)
{
	List list[10];
	for (int i = 0; i < 10; i++)
	{
		ListInit(&list[i]);
	}
	for (int i = 0; i < CAR; i++)
	{
		//�ַ�
		for (int j = start; j <= end; j++)
		{
			ListPushBack(&list[value[j] / (int)pow(10, i) % 10], value[j]);
		}
		//����
		int index = start;
		int j = 0;
		while (index <= end && j < 10)
		{
			if (list[j].Head == NULL)
				j++;
			else
			{
				value[index] = list[j].Head->data;
				ListPopFront(&list[j]);
				index++;
			}
		}
	}
}