#include<iostream>
#include<string>
using namespace std;

int value(char ch)
{
	switch (ch)
	{
	case '3': return 1;
	case '4': return 2;
	case '5': return 3;
	case '6': return 4;
	case '7': return 5;
	case '8': return 6;
	case '9': return 7;
	case 'X': return 8;
	case 'J': return 9;
	case 'Q': return 10;
	case 'K': return 11;
	case 'A': return 12;
	case '2': return 13;
	default: return 14;
	}
}

char ch(string poker)
{
	if (poker[1] == ' ' || poker[0] == 'j')
		return poker[0];
	else
		return 'X';
}

bool compare(string poker1, string poker2)
{
	return value(ch(poker1)) > value(ch(poker2));
}

int main()
{
	string cinstr;
	getline(cin, cinstr);
	string poker1, poker2;
	int count1 = 0, count2 = 0;
	auto it = cinstr.begin();
	while (*it != '-')
	{
		poker1.push_back(*it);
		if (*it == ' ')
			++count1;
		++it;
	}
	++it;
	while (it != cinstr.end())
	{
		poker2.push_back(*it);
		if (*it == ' ')
			++count2;
		++it;
	}

	if (count1 != count2)
	{
		if ((count1 != 3 && count2 != 3) && (value(ch(poker1)) != 14 && value(ch(poker2)) != 14))
			cout << "ERROR" << endl;
		else
		{
			if (value(ch(poker1)) == 14 || ((count1 == 3) && value(ch(poker2)) != 14))
				cout << poker1.c_str() << endl;
			else
				cout << poker2.c_str() << endl;
		}
	}
	else
	{
		if (compare(poker1, poker2))
			cout << poker1.c_str() << endl;
		else
			cout << poker2.c_str() << endl;
	}
	return 0;
}