#include<iostream>
#include<queue>
#include<math.h>
#include<vector>
using namespace std;

bool issushu(int value)
{
	for (int i = 2; i <= sqrt(value); i++)
	if (value % i == 0)
		return false;
	return true;
}

int main()
{
	vector<int> values;
	int temp;
	while (cin >> temp)
	{
		if (temp == 0)
			break;
		values.push_back(temp);
	}
	auto it = values.begin();
	while (it != values.end())
	{
		int x = *it;
		queue<int> res;
		int sushu = 2;
		while (sushu <= *it)
		{
			if (*it % sushu == 0)
			{
				res.push(sushu);
				*it /= sushu;
			}
			else
			{
				while (1)
				{
					sushu++;
					if (issushu(sushu))
						break;
				}
			}
		}
		cout << x << " = ";
		while (!res.empty())
		{
			cout << res.front();
			res.pop();
			if (res.empty())
				break;
			cout << " * ";
		}
		cout << endl;
		++it;
	}
	return 0;
}