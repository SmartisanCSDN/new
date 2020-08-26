#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<functional>
using namespace std;

int main()
{
	set<int, greater<int>>
		int n = 0;
	cin >> n;
	vector<int> value;
	for (int i = 0; i < n; i++)
	{
		int a = 0;
		cin >> a;
		value.push_back(a);
	}
	sort(value.begin(), value.end(), greater<int>());
	int count = 0;
	int min = 0;
	auto it = value.rbegin();
	count = *it - *(++it);
	min = *it;
	while (it != value.rend())
	{
		++it;
		int temp = min - *it;
		count += pow(2, temp);
		min = *it;
	}
	cout << count;
	return 0;
}



//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//int main()
//{
//	string str;
//	cin >> str;
//	vector<vector<int>> hash(10, vector<int>());
//	int i = 0;
//	auto it_str = str.begin();
//	while (it_str != str.end())
//	{
//		hash[*it_str - '0'].push_back(i);
//		++it_str;
//		++i;
//	}
//	int n = 0;
//	cin >> n;
//	vector<int> todo(10, -1);
//	for (int i = 0; i < n; i++)
//	{
//		int a = 0, b = 0;
//		cin >> a >> b;
//		todo[a] = b;
//		for (int j = 0; j < 10; j++)
//		{
//			if (todo[j] == a)
//				todo[j] = b;
//		}
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		if (todo[i] >= 0)
//		{
//			auto it = hash[i].begin();
//			while (it != hash[i].end())
//			{
//				str[*it] = todo[i] + '0';
//				++it;
//			}
//		}
//	}
//	cout << str << endl;
//	return 0;
//}



//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//struct point
//{
//	int x = 0;
//	int y = 0;
//};
//
//int main()
//{
//	string str;
//	cin >> str;
//	point pot;
//	vector<point> way;
//	way.push_back(pot);
//	auto it = str.begin();
//	while (it != str.end())
//	{
//		switch (*it)
//		{
//		case 'N': pot.y += 1;
//		case 'S': pot.y -= 1;
//		case 'W': pot.x += 1;
//		case 'E': pot.x -= 1;
//		}
//		auto it_way = way.begin();
//		while (it_way != way.end())
//		{
//			if (it_way->x == pot.x && it_way->y == pot.y)
//			{
//				cout << "True" << endl;
//				return 0;
//			}
//			++it_way;
//		}
//		way.push_back(pot);
//		++it;
//	}
//	cout << "False" << endl;
//	return 0;
//}