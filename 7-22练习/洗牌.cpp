#include<iostream>
#include<vector>
using namespace std;

struct value
{
	int n;
	int k;
	vector<int> _value;
};

int main()
{
	int T;
	cin >> T;
	vector<value> num;
	for (int i = 0; i < T; i++)
	{
		num.push_back(value());
		cin >> num[i].n;
		cin >> num[i].k;
		for (int j = 0; j < 2 * num[i].n; j++)
		{
			int temp = 0;
			cin >> temp;
			num[i]._value.push_back(temp);
		}
		for (int k = 1; k <= num[i].k; ++k)
		{
			vector<int> temp;
			for (int x = num[i].n; x < 2 * num[i].n; ++x)
			{
				temp.push_back(num[i]._value[x - num[i].n]);
				temp.push_back(num[i]._value[x]);
			}
			num[i]._value.swap(temp);
		}
	}
	for (int i = 0; i < T; ++i)
	{
		for (int j = 0; j < 2 * num[i].n; ++j)
		{
			cout << num[i]._value[j];
			if (j == 2 * num[i].n)
				break;
			cout << " ";
		}
		cout << endl;
	}
	return 0;
}