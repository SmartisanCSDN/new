//----------------

class Solution
{
public:
	int singleNumber(vector<int>& nums)
	{
		int x = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			x = x ^ nums[i];
		}
		return x;
	}
};

//------------------

class Solution
{
public:
	int singleNumber(vector<int>& nums)
	{
		int once = 0;
		int twice = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			once = ~twice & (once ^ nums[i]);
			twice = ~once & (twice ^ nums[i]);
		}
		return once;
	}
};

//---------------------------------

class Solution
{
public:
	vector<int> singleNumber(vector<int>& nums)
	{
		int tnum = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			tnum ^= nums[i];
		}
		int flag = tnum & (-tnum);
		int x = 0;
		for (int i = 0; i < nums.size(); ++i)
		if (flag & nums[i])
			x ^= nums[i];
		int y = tnum ^ x;
		vector<int> rv;
		rv.push_back(x);
		rv.push_back(y);
		return rv;
	}
};