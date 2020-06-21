class Solution
{
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV)
	{
		stack<int> stack;
		int flag = 0;
		for (int i = 0; i < pushV.size(); ++i)
		{
			stack.push(pushV[i]);
			while (!stack.empty() && stack.top() == popV[flag])
			{
				stack.pop();
				++flag;
			}
		}
		if (stack.empty())
			return true;
		else
			return false;
	}
};