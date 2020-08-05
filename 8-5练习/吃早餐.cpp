#include<iostream>
#include<vector>
using namespace std;

struct pa
{
	int from;
	int to;
};

int main()
{
	vector<pa> day;
	pa temp;
	while (cin >> temp.from >> temp.to)
	{
		if (temp.from == 0)
			break;
		day.push_back(temp);
	}
	auto it = day.begin();
	while (it != day.end())
	{
		int a = 0, b = 1;
		int count = 0;
		for (int i = 1; i < it->from; i++)
		{
			int temp = a + b;
			a = b;
			b = temp;
		}
		for (int i = it->from; i <= it->to; i++)
		{
			int temp = a + b;
			a = b;
			b = temp;
			count += a;
		}
		cout << count << endl;
		++it;
	}
	return 0;
}