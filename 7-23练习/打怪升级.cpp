#include<iostream>
#include<vector>
using namespace std;

class greap
{
public:
	void play()
	{
		auto it = destory.begin();
		while (it != destory.end())
		{
			if (a > *it)
				a += *it;
			else
				a += num(a, *it);
			++it;
		}
	}
	int num(int a, int b)
	{
		for (int i = a; i >= 1; --i)
		{
			if (a % i == 0 && b % i == 0)
				return i;
		}
	}
	int a;
	int n;
	vector<int> destory;
};


int main()
{
	vector<greap> value;
	int n = 0, a = 0;
	while (cin >> n >> a)
	{
		//cin >> a;
		value.push_back(greap());
		value.back().n = n;
		value.back().a = a;
		for (int i = 0; i < n; ++i)
		{
			int temp = 0;
			cin >> temp;
			value.back().destory.push_back(temp);
		}
	}
	auto it = value.begin();
	while (it != value.end())
	{
		(*it).play();
		cout << (*it).a << endl;
		++it;
	}
	return 0;
}