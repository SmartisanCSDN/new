#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;



struct value
{
	string len;
	string radius;
};

string add(string str1, string str2)
{
	int advance = 0;
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	if (str2.size() > str1.size())
		str1.swap(str2);
	int i = 0;
	for (i = 0; i < str2.size(); i++)
	{
		advance += str1[i] - '0' + str2[i] - '0';
		str1[i] = advance % 10 + '0';
		advance /= 10;
	}
	while (i < str1.size())
	{
		advance += str1[i] - '0';
		str1[i] = advance % 10 + '0';
		advance /= 10;
		i++;
	}
	if (advance != 0)
		str1 += advance + '0';
	reverse(str1.begin(), str1.end());
	return str1;
}
string pro(string str, int x)
{
	int advance = 0;
	reverse(str.begin(), str.end());
	for (int i = 0; i < str.size(); i++)
	{
		advance += (str[i] - '0') * x;
		str[i] = advance % 10 + '0';
		advance /= 10;
	}
	if (advance != 0)
		str += advance + '0';
	reverse(str.begin(), str.end());
	return str;
}

bool compare(string str1, string str2)
{
	if (str1.size() > str2.size())
		return true;
	else if (str1.size() == str2.size())
	{
		for (int i = 0; i < str1.size(); i++)
		{
			if (str1[i] > str2[i])
				return true;
			else if (str1[i] < str2[i])
				return false;
		}
		return true;
	}
	return false;
}
int main()
{
	vector<value> pairs;
	value tpair;
	while (cin >> tpair.len >> tpair.radius)
	{
		if (tpair.len[0] == '0')
			break;
		pairs.push_back(tpair);
	}
	auto it = pairs.begin();
	while (it != pairs.end())
	{
		it->radius = pro(it->radius, 2);
		string str1 = pro(it->radius, 3);
		string str2 = it->radius;
		str2.pop_back();
		string str3 = pro(it->radius, 4);
		if (!str3.empty())
			str3.pop_back();
		if (!str3.empty())
			str3.pop_back();
		str1 = add(str1, str2);
		it->radius = add(str1, str3);
		if (compare(it->radius, it->len))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		++it;
	}
	return 0;
}