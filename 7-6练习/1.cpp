#include<iostream>

using namespace std;

int main()
{
	int N = 0;
	cin >> N;
	int x = 0, y = 1;
	while (y < N)
	{
		int z = x + y;
		x = y;
		y = z;
	}
	cout << ((y - N) < (N - x) ? (y - N) : (N - x)) << endl;
	return 0;
}