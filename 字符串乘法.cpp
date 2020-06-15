class Solution
{
public:
	void add(char *pro, int product, int index)
	{
		for (int i = index;; ++i)
		{
			product += pro[i] == '\0' ? pro[i] : pro[i] - '0';
			pro[i] = product % 10 + '0';
			product /= 10;
			if (product == 0)
				break;
		}
	}
	void reverse(char *pro, int start, int end)
	{
		while (start < end)
		{
			char temp = pro[start];
			pro[start] = pro[end];
			pro[end] = temp;
			++start;
			--end;
		}
	}
	string multiply(string num1, string num2)
	{
		if (num1.empty())
			return num2;
		if (num2.empty())
			return num1;
		int len = num1.size() + num2.size();
		char pro[1000] = { '\0' };
		for (int i = num1.size() - 1; i >= 0; --i)
		{
			for (int j = num2.size() - 1; j >= 0; --j)
			{
				int product = (num1[i] - '0') * (num2[j] - '0');
				add(pro, product, (num1.size() - 1) + (num2.size() - 1) - i - j);
			}
		}
		if (pro[0] == '\0')
			pro[0] = '0';
		while (pro[--len] == '\0');
		reverse(pro, 0, len);
		if (pro[0] == '0')
			return string("0");
		else
			return string(pro, pro + len + 1);
	}
};