#ifndef _STACK_H_
#define _STACK_H_

#include"common.h"


namespace mystack
{
	template<class T, class cont = deque<T>>
	class stack
	{
	public:
		stack()
		{}
		bool empty()
		{
			return _con.empty();
		}
		size_t size()
		{
			return _con.size();
		}
		T& top()
		{
			return _con.back();
		}
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_back();
		}
	private:
		cont _con;
	};
}




#endif // _STACK_H_