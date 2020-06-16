#ifndef _QUEUE_H_
#define _QUEUE_H_

#include"common.h"

namespace myqueue
{
	template<class T, class cont = deque<T>>
	class queue
	{
	public:
		queue()
		{}
		bool empty()
		{
			return _con.empty();
		}
		size_t size()
		{
			return _con.size();
		}
		T& back()
		{
			return _con.back();
		}
		T& front()
		{
			return _con.front();
		}
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_front();
		}
	private:
		cont _con;
	};
}



#endif // _QUEUE_H_