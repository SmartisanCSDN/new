#include<iostream>
#include<cmath>
using namespace std;

//int binInsert(int n, int m, int j, int i)
//{
//	int a = 1;
//	while (a < m)
//		a = (a + 1) * 2 - 1;
//	a = a << j;
//	cout << a << endl;
//	n |= a;
//	cout << n << endl;
//	m |= (((unsigned int)(~a) << 1) >> 1);
//	cout << m << endl;
//	n &= m;
//	return n;
//}
int binInsert(int n, int m, int j, int i)
{
	int hid = pow(2, j) - 1;
	hid &= n;
	n = (((n >> j) | m) << j) | hid;
	return n;
}
int main()
{
	int n = 1024, m = 19, j = 2, i = 6;
	cout << binInsert(n, m, 2, 6);
	return 0;
}


bool issushu(int value)
{
	for (int i = 2; i <= sqrt(value); ++i)
	if (value % i == 0)
		return false;
	return true;
}

int main()
{
	int number = 0;
	cin >> number;
	int a = 0, b = number;
	while (b >= number / 2)
	{
		if (issushu(b) && issushu(number - b))
			a = number - b;
		b--;
	}
	cout << a << endl;
	cout << number - a << endl;
	return 0;
}
