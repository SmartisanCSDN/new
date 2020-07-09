#include<iostream>
#include<vector>

using namespace std;

template<class T>
class stack
{
public:
	stack() : top(0), capacity(5){}
public:
	void push(T& value)
	{
		if (top == capacity)
			throw pushOnFull();
		arr[top] = value;
		++top;
	}
	void pop()
	{
		if (st.empty())
			throw popOnEmpty();
		--top;
		arr[top] = 0;
	}
private:
	int top;
	int capacity;
	T arr[5];
};

class pushOnFull
{
public:
	pushOnFull()
	{
		cout << "pushOnFull" << endl;
	}
};

class popOnEmpty
{
public:
	popOnEmpty()
	{
		cout << "popOnEmpty" << endl;
	}
};
int main()
{
	stack<int> st;
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	try
	{
		st.push(arr[0]);
		st.push(arr[1]);
		st.push(arr[2]);
		st.push(arr[3]);
		st.push(arr[4]);
		st.push(arr[5]);
	}
	catch (...)
	{
	}
	return 0;
}