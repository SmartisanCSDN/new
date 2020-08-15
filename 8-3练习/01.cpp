#include<iostream>
#include<vector>
using namespace std;


bool fun(vector<int> num, int value)
{
	if (num.size() == 1 && value == num[0])
		return true;
	for (int i = 0; i < num.size(); i++)
	{
		vector<int> temp = num;
		int x = temp[i];
		auto it = temp.begin();
		for (int j = 0; j < i; j++)
			++it;
		temp.erase(it);
		if (fun(temp, value + x) || fun(temp, value - x) || fun(temp, value * x) || fun(temp, value / x))
			return true;
	}
	return false;
}

int main()
{
	vector<int> num(4);
	for (int i = 0; i < 4; i++)
	{
		cin >> num[i];
	}
	if (fun(num, 24))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	return 0;
}