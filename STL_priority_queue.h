#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

#include"common.h"

namespace mypriority_queue
{
	//less�º���
	template<class T>
	struct less
	{
		bool operator()(const T& left, const T& right)
		{
			return left < right;
		}
	};

	//greater�º���
	template<class T>
	struct greater
	{
		bool operator()(const T& left, const T& right)
		{
			return left > right;
		}
	};


	template<class T, class cont = vector<T>, class compare = less<T>>
	class priority_queue
	{
	public:
		priority_queue() : _con()
		{}
		template<class InputIterator>
		priority_queue(InputIterator first, InputIterator last) : _con(first, last)
		{
			int half = (_con.size() - 2) / 2;
			while (half >= 0)
			{
				_AdjustDown(half);
				--half;
			}
		}
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
			return _con.front();
		}
		void push(const T& x)
		{
			_con.push_back(x);
			_AdjustUp(_con.size() - 1);
		}
		void pop()
		{
			if (empty())
				return;
			swap(_con.front(), _con.back());
			_con.pop_back();
			_AdjustDown(0);
		}
	public:
		//���µ���
		void _AdjustDown(int parent)
		{
			size_t child = (parent * 2) + 1;
			while (child < _con.size())
			{
				//�����Һ����нϴ󣨽�С����
				if (child + 1 < _con.size() && _com(_con[child], _con[child + 1]))
					child += 1;

				//��⸸�ڵ��Ƿ�Ⱥ��Ӵ�С��
				if (_com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = (parent * 2) + 1;
				}
				else
					break;
			}
		}
		//���ϵ���
		void _AdjustUp(int child)
		{
			size_t parent = (child - 1) / 2;
			while (parent >= 0)
			{
				if (_com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
					break;
			}
		}
	private:
		cont _con; //����
		compare _com; //�º���
	};
}





#endif // _PRIORITY_QUEUE_H_