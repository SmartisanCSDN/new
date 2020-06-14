class Solution
{
public:
	void reverse(string& s, int start, int end)
	{
		while (start < end)
		{
			char ch = s[start];
			s[start] = s[end];
			s[end] = ch;
			++start;
			--end;
		}
	}
	string reverseWords(string s)
	{
		if (s.empty())
			return s;
		int start = 0;
		while (start < s.size())
		{
			int end = start;
			while (end < s.size() && s[end] != ' ')
				++end;
			reverse(s, start, end - 1);
			if (end == s.size())
				break;
			start = end + 1;
		}
		return s;
	}
};