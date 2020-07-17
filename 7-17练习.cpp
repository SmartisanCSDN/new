#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		string str3;
		auto it1 = str1.rbegin();
		auto it2 = str2.rbegin();
		int advance = 0;
		while (it1 != str1.rend() && it2 != str2.rend())
		{
			advance += (*it1 - '0') + (*it2 - '0');
			str3 += advance % 10 + '0';
			advance /= 10;
			++it1;
			++it2;
		}
		while (it1 != str1.rend())
		{
			advance += (*it1 - '0');
			str3 += advance % 10 + '0';
			advance /= 10;
			++it1;
		}
		while (it2 != str2.rend())
		{
			advance += (*it2 - '0');
			str3 += advance % 10 + '0';
			advance /= 10;
			++it2;
		}
		if (advance != 0)
			str3 += advance + '0';
		auto it3 = str3.rbegin();
		while (it3 != str3.rend())
		{
			cout << *it3;
			++it3;
		}
		cout << endl;
	}
	return 0;
}