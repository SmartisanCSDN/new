#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	vector<int> thing(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> thing[i];
	vector<int> shunxu(n);
	for (int i = 0; i < n; i++)
		cin >> shunxu[i];

	for (int i = 0; i < n; i++)
	{
		thing[shunxu[i]] = 0;
		int max = 0;
		int sum = 0;
		for (int j = 1; j <= n; j++)
		{
			if (thing[j] == 0 || j == n)
			{
				if (sum > max)
					max = sum;
				sum = 0;
				j++;
			}
			else
			{
				sum += thing[j];
			}
		}
		cout << max << endl;
	}
	return 0;
}




//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//struct pa
//{
//	bool operator<(pa num)
//	{
//		return this->money < num.money;
//	}
//	int money;
//	int id;
//};
//
//int main()
//{
//	int m = 0, n = 0;
//	cin >> n >> m;
//	vector<pa> value;
//	for (int i = 0; i < n; i++)
//	{
//		int v = 0, w = 0;
//		cin >> v >> w;
//		pa temp;
//		temp.money = v + w * 2;
//		temp.id = i + 1;
//		value.push_back(temp);
//	}
//	sort(value.begin(), value.end());
//
//	vector<int> rv;
//	auto it = value.rbegin();
//	for (int i = 1; i <= m; i++)
//	{
//		rv.push_back(it->id);
//		++it;
//	}
//	sort(rv.begin(), rv.end());
//	for (int i = 0; i < m; i++)
//		cout << rv[i] << " ";
//	cout << endl;
//
//	return 0;
//}
