#include<iostream>
#include<list>
#include<string>
using namespace std;

struct mp3
{
	friend ostream& operator<<(ostream& out, const mp3& mp);
	mp3(int n) : n(n), value(1)
	{
		int i = 1;
		while (i <= n && i <= 4)
		{
			view[i] = i;
			i++;
		}
	}
	void adjust(char command)
	{
		if (command == 'U')
			up();
		else
			down();
	}
	void up()
	{
		if (value != view[1])
			value--;
		else
		{
			if (n <= 4)
				value = n;
			else
			{
				if (value == 1)
				{
					value = n;
					for (int i = 1; i <= 4; i++)
						view[i] = n - (4 - i);
				}
				else
				{
					value--;
					for (int i = 1; i <= 4; i++)
						view[i]--;
				}
			}
		}
	}
	void down()
	{
		if (value != view[4])
			value++;
		else
		{
			if (n <= 4)
				value = 1;
			else
			{
				if (value == n)
				{
					value = 1;
					for (int i = 1; i <= 4; i++)
						view[i] = i;
				}
				else
				{
					value++;
					for (int i = 1; i <= 4; i++)
						view[i]++;
				}
			}
		}
	}
	int n;
	int value;
	int view[5];
};

ostream& operator<<(ostream& out, mp3& mp)
{
	for (int i = 1; i <= mp.n && i <= 4; ++i)
	{
		out << mp.view[i];
		if (!(i <= mp.n && i <= 4))
			break;
		out << " ";
	}
	out << endl;
	out << mp.value << endl;
	return out;
}

int main()
{
	int n = 0;
	cin >> n;
	mp3 mp(n);
	cout << mp;
	char ch;
	while (cin >> ch)
	{
		mp.adjust(ch);
		cout << mp;
	}
	return 0;
}