class Solution {
public:
	int cutRope(int n) {
		//利用动规来做
		int *dp = new int[n + 1]();
		//当number小于4的时候，绳子不切才是最大的，但是不能不切，所以要分开判断
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
		//如果大于4，那么3是可以单独领出来的
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