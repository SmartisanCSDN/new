class Solution
{
public:
	int firstUniqChar(string s)
	{
		int fuzhu[26] = { 0 };
		for (const char& ch : s)
		{
			++fuzhu[ch - 'a'];
		}
		int i = 0;
		while (i < s.size())
		{
			if (fuzhu[s[i] - 'a'] == 1)
				break;
			++i;
		}
		if (i == s.size())
			return -1;
		return i;
	}
};