class Solution
{
public:
	void huisu(vector<string>& rv, string& str, vector<string> fuzhu, string digits, int index)
	{
		if (index == digits.size())
		{
			rv.push_back(str);
		}
		else
		{
			for (size_t i = 0; i < fuzhu[digits[index] - '0'].size(); ++i, str.pop_back())
			{
				str.push_back(fuzhu[digits[index] - '0'][i]);
				huisu(rv, str, fuzhu, digits, index + 1);
			}
		}
	}
	vector<string> letterCombinations(string digits)
	{
		vector<string> rv;
		if (digits.empty())
			return rv;
		vector<string> fuzhu(10);
		fuzhu[2] = "abc";
		fuzhu[3] = "def";
		fuzhu[4] = "ghi";
		fuzhu[5] = "jkl";
		fuzhu[6] = "mno";
		fuzhu[7] = "pqrs";
		fuzhu[8] = "tuv";
		fuzhu[9] = "wxyz";
		string str;
		huisu(rv, str, fuzhu, digits, 0);;
		return rv;
	}
};