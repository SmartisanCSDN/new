#include<stdio.h>


int compare_int(const void* p1, const void* p2)
{
	if (*((int*)p1) > *((int*)p2))
		return 1;
	else
		return 0;
}

void swp_int(void* p1, void* p2)
{
	int temp = *((int*)p1);
	*((int*)p1) = *((int*)p2);
	*((int*)p2) = temp;
}

void bubsort(void *base, size_t num, int size, int(*compare)(const void*, const void*), void(*swp)(void*, void*))
{
	for (int i = 0; i < (int)num - 1; i++)
	{
		for (int j = 0; j < (int)num - 1 - i; j++)
		{
			if (compare((char*)base + j * size, (char*)base + (j + 1) * size))
				swp((char*)base + j * size, (char*)base + (j + 1) * size);
			/*if (((int*)base)[j + 1] < ((int*)base)[j])
			{
			int temp = ((int*)base)[j + 1];
			((int*)base)[j + 1] = ((int*)base)[j];
			((int*)base)[j] = temp;
			}*/
		}
	}
}



int main()
{
	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	bubsort(arr, 10, sizeof(int), compare_int, swp_int);
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}