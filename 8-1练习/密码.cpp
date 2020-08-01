#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	vector<string> pwds;
	string pwd;
	while (getline(cin, pwd))
	{
		auto it = pwd.begin();
		while (it != pwd.end())
		{
			if (*it >= 'A' && *it <= 'Z')
			{
				*it = (*it - 'A' - 5 + 26) % 26 + 'A';
			}
			++it;
		}
		pwds.push_back(pwd);
	}
	auto it = pwds.begin();
	while (it != pwds.end())
	{
		cout << *it << endl;
		++it;
	}
	return 0;
}