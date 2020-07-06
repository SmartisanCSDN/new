class Parenthesis
{
public:
	bool chkParenthesis(string A, int n)
	{
		stack<char> stack;
		for (int i = 0; i < n; ++i)
		{
			if (A[i] == '(')
				stack.push('(');
			else if (A[i] == ')')
			{
				if (stack.empty())
					return false;
				stack.pop();
			}
			else
				return false;
		}
		if (stack.empty())
			return true;
		else
			return false;
	}
};