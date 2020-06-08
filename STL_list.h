#ifndef _LIST_H_
#define _LIST_H_


#include<iostream>

using namespace std;


namespace mylist
{
	//list节点类型
	template<class T>
	struct ListNode
	{
		//构造函数，data默认为T类型的0值
		ListNode(const T& data = T()) : _prev(nullptr), _next(nullptr), _data(data){}
		ListNode<T> *_prev;
		ListNode<T> *_next;
		T _date;
	};
	//容器类
	template<class T>
	class list
	{
	public:
		
		//申请节点函数
		ListNode<T>* _ByeNode(T data, ListNode<T> * prev = nullptr, ListNode<T> *next = nullptr)
		{
			ListNode<T> *node = (ListNode<T>*)malloc(sizeof(ListNode<T>));
			node->_prev = prev != nullptr ? prev : node;
			node->_next = next != nullptr ? next : node;
			node->_date = data;
			return node;
		}
		//list构造函数
		list() : _size(0)
		{
			_Head = _ByeNode(0);
		}
		//迭代器类
		class iterator
		{
		public:
			//构造方法
			iterator(ListNode<T> *pNode) : _pNode(pNode){}

		private:
			//迭代器包含一个指向节点类型的指针
			ListNode<T> *_pNode;
		};
		//list的begin()
		iterator begin()
		{
			return iterator(_Head->_next);
		}
		//list的end()
		{
			return iterator(_Head);
		}
	private:
		ListNode<T> *_Head;
		size_t _size;
	};
}








#endif //_LIST_H_