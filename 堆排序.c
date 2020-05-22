//��������ϵ���
void adjustup_small(Heap* php, int index)
{
	assert(php != NULL);
	int temp = php->data[index];
	while (index != 0 && php->data[(index - 1) / 2] < temp)
	{
		php->data[index] = php->data[(index - 1) / 2];
		index = (index - 1) / 2;
	}
	php->data[index] = temp;
}

//��������µ���
void adjustdown_small(Heap* php, int index)
{
	assert(php != NULL);
	int temp = php->data[index];
	while (1)
	{
		if (index * 2 + 1 < php->size && php->data[index * 2 + 1] > temp)
		{
			if (index * 2 + 2 < php->size && php->data[index * 2 + 2] > temp)
			{
				int index_c = 0;
				if (php->data[index * 2 + 1] > php->data[index * 2 + 2])
					index_c = index * 2 + 1;
				else
					index_c = index * 2 + 2;
				php->data[index] = php->data[index_c];
				index = index_c;
			}
			else
			{
				php->data[index] = php->data[index * 2 + 1];
				index = index * 2 + 1;
			}
		}
		else if (index * 2 + 2 < php->size && php->data[index * 2 + 2] > temp)
		{
			php->data[index] = php->data[index * 2 + 2];
			index = index * 2 + 2;
		}
		else
			break;
	}
	php->data[index] = temp;
}

//�ѵĹ���
void HeapCreate(Heap* php, HpDataType* a, int n)
{
	assert(php != NULL);
	php->data = a;
	php->capacity = n;
	php->size = n;
	for (int i = 1; i < n; i++)
	{
		adjustup_small(php, i);
	}
}

//������
void HeapSort(int* value, int start, int end)
{
	assert(value != NULL);
	Heap hp;
	//��value+startΪ��ʼλ�ã�end-start+1��Ԫ�ؽ���
	HeapCreate(&hp, value + start, end - start + 1);
	while (hp.size > 0)
	{
		//���Ѷ�Ԫ�������һ��Ԫ�ؽ���
		hp.size--;
		int temp = hp.data[0];
		hp.data[0] = hp.data[hp.size];
		hp.data[hp.size] = temp;
		//�Ѷ�Ԫ�����µ���
		adjustdown_small(&hp, 0);

	}
}