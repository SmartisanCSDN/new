#include<iostream>
#include<string>
using namespace std;
bool fun(string str1, string str2)
{
	auto it1 = str1.begin(), it2 = str2.begin();
	while (it1 != str1.end() && it2 != str2.end())
	{
		if (*it1 != '*' && *it1 != '?' && *it1 != *it2)
			return false;
		if (*it1 == '*')
		{
			++it1;
			if (it1 == str1.end())
				return true;
			while (it2 != str2.end() && *it1 != *it2)
				++it2;
		}
		else
		{
			++it1;
			++it2;
		}
	}
	if (it1 == str1.end() && it2 == str2.end())
		return true;
	else
		return false;
}
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		if (fun(str1, str2))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}