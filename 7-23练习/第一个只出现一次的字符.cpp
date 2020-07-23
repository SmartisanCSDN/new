#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	while (cin >> str)
	{
		int hash[256] = { 0 };
		auto it = str.begin();
		while (it != str.end())
		{
			hash[*it]++;
			++it;
		}
		it = str.begin();
		while (it != str.end())
		{
			if (hash[*it] == 1)
			{
				cout << *it << endl;
				break;
			}
			++it;
		}
		if (it == str.end())
			cout << -1 << endl;
	}
	return 0;
}