//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//bool islch(char ch)
//{
//	return ch >= 'a' && ch <= 'z';
//}
//
//bool isbch(char ch)
//{
//	return ch >= 'A' && ch <= 'Z';
//}
//
//bool isnum(char ch)
//{
//	return ch >= '0' && ch <= '9';
//}
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<string> strs(n);
//	for (int i = 0; i < n; i++)
//		cin >> strs[i];
//	auto it = strs.begin();
//	while (it != strs.end())
//	{
//		if (!(isbch((*it)[0]) || islch((*it)[0])))
//			cout << "Wrong" << endl;
//		else
//		{
//			auto it_str = it->begin();
//			int flag_num = 0;
//			int flag_ch = 0;
//			int flag_w = 0;
//			while (it_str != it->end())
//			{
//				if (isnum(*it_str))
//					flag_num++;
//				else if (isbch(*it_str) || islch(*it_str))
//					flag_ch++;
//				else
//				{
//					cout << "Wrong" << endl;
//					flag_w = 1;
//					break;
//				}
//				++it_str;
//			}
//			if (flag_w == 0 && flag_num != 0 && flag_ch != 0)
//				cout << "Accept" << endl;
//			else
//				cout << "Wrong" << endl;
//		}
//		++it;
//	}
//	return 0;
//}






//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//struct body
//{
//	int height;
//	int weight;
//	bool operator>(body& body1)
//	{
//		return this->height > body1.height;
//	}
//	bool operator<(body& body1)
//	{
//		return this->height < body1.height;
//	}
//};
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		int gyhj;
//		vector<body> value(n);
//		for (int i = 0; i < n; i++)
//			cin >> gyhj >> value[i].weight >> value[i].height;
//		sort(value.begin(), value.end());
//		for (int i = 0; i < n; i++)
//			cout << value[i].height << " ";
//	}
//	return 0;
//}