void reverser(int add[], int start, int end)
{
	while (start < end)
	{
		int temp = add[start];
		add[start] = add[end];
		add[end] = temp;
		start++;
		end--;
	}
}

int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
{
	int* add;
	add = (int*)malloc(sizeof(int)* (ASize + 5));
	for (int i = 0; i < ASize; i++)
	{
		K += A[ASize - i - 1];
		add[i] = K % 10;
		K /= 10;
	}
	while (K > 0)
	{
		add[ASize++] = K % 10;
		K /= 10;
	}
	reverser(add, 0, ASize - 1);
	*returnSize = ASize;
	return add;
}