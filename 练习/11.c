void SeqListInit(SeqList* ps)
{
	assert(ps != NULL);
	ps->a = (SeqList *)malloc(sizeof(SLDateType)* 10);
	for (int i = 0; i < 10; i++)
		ps->a[i] = 0;
	ps->size = 0;
	ps->capacity = 10;
}

void SeqListDestory(SeqList* ps)
{
	assert(ps != NULL);
	free(ps->a);
	free(ps);
}


void SeqListPrint(SeqList* ps)
{
	assert(ps != NULL);
	for (int i = 0; i < ps->size; i++)
		printf("%d ", ps->a[i]);
	printf("\n");
}

void SeqListPushBack(SeqList* ps, SLDateType x)
{
	assert(ps != NULL);
	if (ps->size == ps->capacity)
	{
		ps = realloc(ps, sizeof(SLDateType)* ps->capacity * 2);
		ps->capacity *= 2;
	}
	ps->a[ps->size] == x;
	ps->size++;
}

void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps != NULL);
	if (ps->size == ps->capacity)
	{
		ps = realloc(ps, sizeof(SLDateType)* ps->capacity * 2);
		ps->capacity *= 2;
	}
	for (int i = ps->size; i > 0; i--)
		ps->a[i] = ps->a[i - 1];
	ps->a[0] = x;
	ps->size++;
}

void SeqListPopFront(SeqList* ps)
{
	assert(ps != NULL);
	if (ps->size == 0)
		printf("线性表空，无法删除！\n");
	else
	{
		for (int i = 0; i < ps->size; i++)
			ps->a[i] == ps->a[i + 1];
		ps->size--;
	}
}


void SeqListPopBack(SeqList* ps)
{
	assert(ps != NULL);
	if (ps->size == 0)
		printf("线性表空，无法删除！\n");
	else
	{
		ps->size--;
		ps->a[ps->size] = 0;
	}
}


int SeqListFind(SeqList* ps, SLDateType x)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
			return i;
	}
	return -1;
}


void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	assert(ps != NULL);
	if (ps->size == ps->capacity)
	{
		ps = realloc(ps, sizeof(SLDateType)* ps->capacity * 2);
		ps->capacity *= 2;
	}
	for (int i = ps->size; i > pos; i--)
		ps->a[i] = ps->a[i - 1];
	ps->a[pos] = x;
	ps->size++;
}


void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps != NULL);
	if (ps->size == 0)
		printf("线性表空，无法删除！\n");
	else
	{
		for (int i = pos; i < ps->size, i++)
			ps->a[i] = ps->a[i + 1];
		ps->size--;
	}
}