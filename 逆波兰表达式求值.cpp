class Solution
{
public:
	int evalRPN(vector<string>& tokens)
	{
		stack<int> stack;
		for (int i = 0; i < tokens.size(); ++i)
		{
			if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
			{
				int num1 = stack.top();
				stack.pop();
				int num2 = stack.top();
				stack.pop();
				switch (tokens[i][0])
				{
				case '+':
					num2 += num1; break;
				case '-':
					num2 -= num1; break;
				case '*':
					num2 *= num1; break;
				case '/':
					num2 /= num1; break;
				}
				stack.push(num2);
			}
			else
				stack.push(stoi(tokens[i]));
		}
		return stack.top();
	}
};