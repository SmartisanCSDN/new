#include<stdio.h>
#include<math.h>
int main()
{
	for (int i = 0; i <= 100000; i++)
	{
		int count = 0;
		int tmp = i;
		//判断i是否为水仙花数
		//1. 求判断数字的位数
		while (tmp > 0)
		{
			count++;
			tmp = tmp / 10;
		}
		//2. 计算每一位的次方和
		int sum = 0;
		tmp = i;
		while (tmp > 0)
		{
			sum += pow(tmp % 10, count);
			tmp = tmp / 10;
		}
		//3. 判断
		if (sum == i)
			printf("%d ", i);
	}
	return 0;
}