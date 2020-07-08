#include<iostream>
using namespace std;

int fun(int n, int m, int x, int y)
{
	if (x == n || y == m)
		return 1;
	else
		return fun(n, m, x + 1, y) + fun(n, m, x, y + 1);
}

int hanshu(int n, int m)
{
	return fun(n, m, 0, 0);
}
int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	if (n == 0 || m == 0)
	{
		cout << 1 << endl;
		return 0;
	}
	cout << hanshu(n, m) << endl;
	return 0;
}


class UnusualAdd
{
public:
	int addAB(int A, int B)
	{
		if (A == 0)
			return B;
		while (B != 0)
		{
			int temp = (A & B) << 1;
			A = A ^ B;
			B = temp;
		}
		return A;
	}
};s