#include<stdio.h>
#include<math.h>
int main()
{
	for (int i = 0; i <= 100000; i++)
	{
		int count = 0;
		int tmp = i;
		//�ж�i�Ƿ�Ϊˮ�ɻ���
		//1. ���ж����ֵ�λ��
		while (tmp > 0)
		{
			count++;
			tmp = tmp / 10;
		}
		//2. ����ÿһλ�Ĵη���
		int sum = 0;
		tmp = i;
		while (tmp > 0)
		{
			sum += pow(tmp % 10, count);
			tmp = tmp / 10;
		}
		//3. �ж�
		if (sum == i)
			printf("%d ", i);
	}
	return 0;
}