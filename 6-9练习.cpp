#include<iostream>
#include<list>
#include<string>

using namespace std;


int main()
{
	string str1;
	string str2("ABCDEF");
	string str3("CDE");

	string str4 = str2.substr(10, 2);


	cout << str2[6] << endl;
	cout << str2.at(5) << endl;

	//string str5;
	//cin >> str5;
	////getline(cin, str5);
	//cout << str5 << endl;

	/*str2.push_back('s');
	str2.append("dadfas");*/

	//const char *str4 = str2.c_str();

	/*str2.append("s");

	int pos = str2.rfind(str3);

	if (pos != string::npos)
	cout << pos << endl;
	else
	cout << "no find" << endl;*/
	/*cout << str1.capacity() << endl;
	cout << str2.capacity() << endl;
	cout << str3.capacity() << endl;

	str1.reserve(100);
	cout << str1.capacity() << endl;
	str3.resize(10);
	cout << str3 << endl;*/

	/*cout << str1 << endl;
	cout << str1.size() << endl;
	cout << str2.size() << endl;
	cout << str3.size() << endl;
	string str4(str2);
	cout << str4.size() << endl;
	cout << str2.empty() << endl;*/





	/*int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	list<int> list1;
	list<int> list2(arr, arr + 10);
	list<int> list3(arr, arr + 10);
	list<int> list4(list3);
	list<int> list5(list2.begin(), list2.end());


	list2.merge(list3);
	list<int>::iterator it = list2.begin();
	while (it != list2.end())
	{
	cout << *it << " ";
	++it;
	}
	cout << endl;*/

	//auto it = list3.rbegin();
	//while (it != list3.rend())
	//{
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;


	//bool tf = list1.empty();
	//cout << tf << endl;


	//size_t size = list3.size();
	//cout << size << endl;

	//cout << list3.front() << endl;
	//cout << list3.back() << endl;


	//list3.push_front(100);
	//list3.push_back(1000);
	//auto it1 = list3.begin();
	//while (it1 != list3.end())
	//{
	//	cout << *it1 << " ";
	//	++it1;
	//}
	//cout << endl;


	//list3.pop_front();
	//list3.pop_back();
	//it1 = list3.begin();
	//while (it1 != list3.end())
	//{
	//	cout << *it1 << " ";
	//	++it1;
	//}
	//cout << endl;

	/*auto it1 = list3.begin();
	++it1;
	++it1;
	it1 = list3.insert(it1, 100);
	cout << *it1 << endl;
	it1 = list3.begin();
	while (it1 != list3.end())
	{
	cout << *it1 << " ";
	++it1;
	}
	cout << endl;*/


	/*auto it1 = list3.begin();
	++it1;
	++it1;
	it1 = list3.erase(it1);
	cout << *it1 << endl;
	it1 = list3.begin();
	while (it1 != list3.end())
	{
	cout << *it1 << " ";
	++it1;
	}
	cout << endl;*/


	/*auto it = find(list3.begin(), list3.end(), 5);
	cout << *it << endl;
	it = list3.erase(it);
	cout << *it << endl;
	it = list3.begin();
	while (it != list3.end())
	{
	cout << *it << " ";
	++it;
	}
	cout << endl;
	*/

	/*list2.swap(list3);
	auto it = list2.begin();
	while (it != list2.end())
	{
	cout << *it << " ";
	++it;
	}
	cout << endl;
	it = list3.begin();
	while (it != list3.end())
	{
	cout << *it << " ";
	++it;
	}
	cout << endl;*/


	/*list2.clear();
	cout << list2.size() << endl;*/



	return 0;
}