#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int fei[100001] = { 0, 1, 2 };
	for (int i = 3; i <= 100000; i++)
		fei[i] = (fei[i - 1] + fei[i - 2]) % 1000000;
	vector<int> value;
	int temp = 0;
	while (cin >> temp)
	{
		if (temp == 0)
			break;
		value.push_back(temp);
	}
	auto it = value.begin();
	while (it != value.end())
	{
		cout << fei[*it] << endl;
		++it;
	}
}


//#include<iostream>
//#include<vector>
//using namespace std;
//
//struct date
//{
//	int year;
//	int month;
//	int day;
//};
//struct pa
//{
//	date date1;
//	date date2;
//};
//
//int main()
//{
//	int months[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	int m_m[13];
//	for (int i = 1; i <= 12; i++)
//	{
//		if (i == 2 || i == 3 || i == 5 || i == 7 || i == 11)
//			m_m[i] = months[i];
//		else
//			m_m[i] = months[i] * 2;
//	}
//
//	vector<pa> value;
//	pa pt;
//	while (1)
//	{
//		cin >> pt.date1.year >> pt.date1.month >> pt.date1.day;
//		if (pt.date1.year == 0)
//			break;
//		cin >> pt.date2.year >> pt.date2.month >> pt.date2.day;
//		value.push_back(pt);
//	}
//
//	auto it = value.begin();
//	while (it != value.end())
//	{
//		int count = 0;
//		if (it->date1.year == it->date2.year && it->date1.month == it->date2.month)
//		{
//			if (it->date1.month == 2 || it->date1.month == 3 || it->date1.month == 5 || it->date1.month == 7 || it->date1.month == 11)
//				count += it->date2.day - it->date1.day + 1;
//			else
//				count += (it->date2.day - it->date1.day + 1) * 2;
//		}
//		else
//		{
//			int temp = months[it->date1.month] - it->date1.day + 1;
//			if (it->date1.month == 2 && ((it->date1.year % 4 == 0 && it->date1.year % 100 != 0) || it->date1.year % 400 == 0))
//				temp += 1;
//			if (it->date1.month == 2 || it->date1.month == 3 || it->date1.month == 5 || it->date1.month == 7 || it->date1.month == 11)
//				count += temp;
//			else
//				count += temp * 2;
//			it->date1.month = it->date1.month % 12 + 1;
//			if (it->date1.month == 1)
//				it->date1.year++;
//			while (!(it->date1.year == it->date2.year && it->date1.month == it->date2.month))
//			{
//				int temp = m_m[it->date1.month];
//				if (it->date1.month == 2 && ((it->date1.year % 4 == 0 && it->date1.year % 100 != 0) || it->date1.year % 400 == 0))
//					temp += 1;
//				count += temp;
//
//				it->date1.month = it->date1.month % 12 + 1;
//				if (it->date1.month == 1)
//					it->date1.year++;
//			}
//			if (it->date2.month == 2 || it->date2.month == 3 || it->date2.month == 5 || it->date2.month == 7 || it->date2.month == 11)
//				count += it->date2.day;
//			else
//				count += it->date2.day * 2;
//		}
//		cout << count << endl;
//		++it;
//	}
//
//	return 0;
//}

