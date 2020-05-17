void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int pf = m + n - 1;
	m = m - 1;
	n = n - 1;
	while (m >= 0 && n >= 0)
	{
		if (nums1[m] > nums2[n])
		{
			nums1[pf] = nums1[m];
			m--;
		}
		else
		{
			nums1[pf] = nums2[n];
			n--;
		}
		pf--;
	}
	while (n >= 0)
	{
		nums1[pf] = nums2[n];
		n--;
		pf--;
	}
}