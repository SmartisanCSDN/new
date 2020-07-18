#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n = 0;
	while (cin >> n)
	{
		vector<int> tuzi;
		tuzi.push_back(1);
		for (int i = 1; i < n; ++i)
		{
			auto it = tuzi.begin();
			int count = 0;
			while (it != tuzi.end())
			{
				++(*it);
				if (*it >= 3)
					++count;
				++it;
			}
			for (int i = 1; i <= count; ++i)
				tuzi.push_back(1);
		}
		cout << tuzi.size() << endl;
	}
	return 0;
}