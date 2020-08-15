#include<iostream>
//#include<vector>
//using namespace std;
//
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//int fun(unsigned x)
//{
//	if (x <= 3)
//		return 1;
//	return fun(x / 2) + 1;
//}
//
//int main()
//{
//	vector<unsigned int> value;
//	unsigned int temp = 0;
//	while (cin >> temp)
//	{
//		if (temp == 0)
//			break;
//		value.push_back(temp);
//	}
//	for (int i = 0; i < value.size(); i++)
//	{
//		cout << fun(value[i]) << endl;
//	}
//}


//class BigInt
//{
//public:
//	void Add(BigInt &bt, const BigInt &bt1, const BigInt &bt2)
//	{
//
//	}
//};
//
//void BigInt::Add(BigInt &bt, const BigInt &bt1, const BigInt &bt2)
//{
//	int x = 0;
//	size_t index = 1;
//	while (index <= bt1.size() && index <= bt2.size())
//	{
//		x += bt1[i] - '0' + bt2[i] - '0';
//		bt.push_back(x % 10 + '0');
//		x /= 10;
//		index++;
//	}
//	while (index <= bt1.size())
//	{
//		x += bt1[i] - '0';
//		bt.push_back(x % 10 + '0');
//		x /= 10;
//		index++;
//	}
//	while (index <= bt2.size())
//	{
//		x += bt2[i] - '0';
//		bt.push_back(x % 10 + '0');
//		x /= 10;
//		index++;
//	}
//	if (x != 0)
//		bt.push_back(x + '0');
//}