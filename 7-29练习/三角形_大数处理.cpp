#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct tri
{
	string a;
	string b;
	string c;
};

string add(string str1, string str2)
{
	string str;
	int value = 0;
	auto it1 = str1.rbegin();
	auto it2 = str2.rbegin();
	while (it1 != str1.rend() && it2 != str2.rend())
	{
		value += *it1 - '0' + *it2 - '0';
		str += value % 10 + '0';
		value /= 10;
		++it1;
		++it2;
	}
	while (it1 != str1.rend())
	{
		value += *it1 - '0';
		str += value % 10 + '0';
		value /= 10;
		++it1;
	}
	while (it2 != str2.rend())
	{
		value += *it2 - '0';
		str += value % 10 + '0';
		value /= 10;
		++it2;
	}
	if (value != 0)
		str += value + '0';
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
	}
	return false;
}

int main()
{
	vector<tri> values;
	tri temp;
	while (cin >> temp.a >> temp.b >> temp.c)
	{
		if (temp.a[0] == '0')
			break;
		values.push_back(temp);
	}

	auto it = values.begin();
	while (it != values.end())
	{
		if (compare(add(it->a, it->b), it->c) && compare(add(it->a, it->c), it->b) && compare(add(it->b, it->c), it->a))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		++it;
	}
	return 0;
}