#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	auto begin1 = str1.begin();
	int count = 0;
	while (begin1 != str1.end())
	{
		auto begin2 = str2.begin();
		while (begin2 != str2.end())
		{
			auto end1 = begin1;
			auto end2 = begin2;
			int temp = 0;
			while (end1 != str1.end() && end2 != str2.end() && *end1 == *end2)
			{
				++temp;
				++end1;
				++end2;
			}
			if (temp > count)
				count = temp;
			++begin2;
		}
		++begin1;
	}
	cout << count << endl;
}