int removeElement(int* nums, int numsSize, int val)
{
	int count = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] == val)
			count++;
		else
			nums[i - count] = nums[i];

	}
	int newsize = numsSize - count;
	for (int i = newsize; i < numsSize; i++)
		nums[i] = 0;
	return newsize;
}