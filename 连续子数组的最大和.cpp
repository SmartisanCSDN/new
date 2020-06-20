class Solution
{
public:
	int FindGreatestSumOfSubArray(vector<int> array)
	{
		int max = array[0];
		//i������
		for (int i = 1; i <= array.size(); ++i)
		{
			//j������ʼλ��
			for (int j = 0; j < array.size() - i + 1; ++j)
			{
				int temp = 0;
				for (int k = j; k < j + i; ++k)
					temp += array[k];
				if (temp > max)
					max = temp;
				temp = 0;
			}
		}
		return max;
	}
};
