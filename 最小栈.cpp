class MinStack {
public:
	MinStack() : _stack(), _minstack()
	{
	}

	void push(int x)
	{
		_stack.push(x);
		if (_minstack.empty() || x <= _minstack.top())
			_minstack.push(x);
	}

	void pop()
	{
		if (_minstack.top() == _stack.top())
			_minstack.pop();
		_stack.pop();
	}

	int top()
	{
		return _stack.top();
	}

	int getMin()
	{
		return _minstack.top();
	}
private:
	stack<int> _stack;
	stack<int> _minstack;
};