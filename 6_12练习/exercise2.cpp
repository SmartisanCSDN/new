class Solution
{
public:
	string reverseOnlyLetters(string S)
	{
		if (S.empty())
			return S;
		string::iterator first = S.begin();
		string::iterator last = S.end();
		--last;
		while (first < last)
		{
			while (first < last && !((*first >= 'a' && *first <= 'z') || (*first >= 'A' && *first <= 'Z')))
				++first;
			while (first < last && !((*last >= 'a' && *last <= 'z') || (*last >= 'A' && *last <= 'Z')))
				--last;
			char temp = *first;
			*first = *last;
			*last = temp;
			++first;
			--last;
		}
		return S;
	}
};