//#include<iostream>
//#include<stdio.h>
//using namespace std;
//
//int main()
//{
//	double choose[21] = { 0, 1, 1 };
//	for (int i = 3; i <= 20; i++)
//	{
//		choose[i] = choose[i - 1] * (i - 1);
//	}
//	int n = 0;
//	while (cin >> n)
//	{
//		double all = 1;
//		for (int i = 2; i <= n; i++)
//			all *= i;
//		double r = choose[n] * 100 / all;
//		printf("%.2f%%\n", r);
//	}
//	return 0;
//}
//


//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	string names;
//	string name;
//	while (1)
//	{
//		getline(cin, names);
//		getline(cin, name);
//		auto it = names.begin();
//		int flag = 0;
//		while (it != names.end())
//		{
//			string str;
//			if (*it == '\"')
//			{
//				++it;
//				while (*it != '\"')
//				{
//					str += *it;
//					++it;
//				}
//				++it;
//			}
//			else
//			{
//				while (it != names.end() && *it != ',')
//				{
//					str += *it;
//					++it;
//				}
//			}
//			if (str == name)
//			{
//				cout << "Ignore" << endl;
//				flag = 1;
//				break;
//			}
//			if (it != names.end())
//				++it;
//		}
//		if (flag == 0)
//			cout << "Important!" << endl;
//	}
//	return 0;
//}





//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		
//	}
//	return 0;
//}
//


//#include<iostream>
//#include<vector>
//#include<math.h>
//using namespace std;
//
//int main()
//{
//	vector<int> value;
//	int n = 0;
//	while (cin >> n)
//	{
//		if (n == 0)
//			break;
//		value.push_back(n);
//	}
//	auto it = value.begin();
//	while (it != value.end())
//	{
//		int a = 1, b = 1;
//		for (int i = 1; i < *it; i++)
//		{
//			int temp = a + b;
//			a = b;
//			b = temp;
//		}
//		cout << a << endl;
//		++it;
//	}
//	return 0;
//}



//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		fflush(stdin);
//		vector<string> value(n);
//		for (int i = 0; i < n; i++)
//			getline(cin, value[i]);
//		for (int i = 0; i < value.size(); i++)
//		{
//			int flag = 0;
//			auto it = value[i].begin();
//			while (it != value[i].end())
//			{
//				if (*it == ',' || *it == ' ')
//				{
//					flag = 1;
//					break;
//				}
//				++it;
//			}
//			if (flag)
//				cout << "\"";
//			cout << value[i];
//			if (flag)
//				cout << "\"";
//			if (i != value.size() - 1)
//				cout << ", ";
//		}
//		cout << endl;
//	}
//	return 0;
//}
