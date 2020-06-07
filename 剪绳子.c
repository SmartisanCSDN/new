class Solution {
public:
	int cutRope(int n) {
		//���ö�������
		int *dp = new int[n + 1]();
		//��numberС��4��ʱ�����Ӳ��в������ģ����ǲ��ܲ��У�����Ҫ�ֿ��ж�
		if (n <= 1)
		{
			return 0;
		}
		if (n == 2)
		{
			return 1;
		}
		if (n == 3)
		{
			return 2;
		}
		//�������4����ô3�ǿ��Ե����������
		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 3;
		for (int i = 4; i<n + 1; i++)
		{
			for (int j = 1; j<(i + 1) / 2 + 1; j++)
			{
				dp[i] = max(dp[i], dp[i - j] * dp[j]);
			}
		}
		return dp[n];
	}
};