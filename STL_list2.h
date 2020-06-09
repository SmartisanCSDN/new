#ifndef _LIST_H_
#define _LIST_H_

#include<iostream>
#include<assert.h>

using namespace std;


namespace mylist
{
	template<class T>
	class list;
	template<class T>
	class iterator;
	template<class T>
	struct ListNode
	{
	public:
		friend class list<T>;
		friend class iterator<T>;
		ListNode(T data = T()) : _prev(nullptr), _next(nullptr), _data(data){}
	private:
		ListNode *_prev;
		ListNode *_next;
		T _data;
	};

	//迭代器
	template<class T>
	class iterator
	{
	public:
		typedef ListNode<T>* pNode;
	public:
		iterator(pNode pNode = nullptr) : _pNode(pNode){}
	public:
		T& operator*()
		{
			return _pNode->_data;
		}
		T* operator->()
		{
			return &(operator*());
		}
	public:
		iterator& operator++()
		{
			_pNode = _pNode->_next;
			return *this;
		}
		iterator operator++(int)
		{
			iterator<T> it = *this;
			_pNode = _pNode->_next;
			return it;
		}
		iterator operator--()
		{
			_pNode = _pNode->_prev;
			return *this;
		}
		iterator operator--(int)
		{
			iterator<T> it = *this;
			_pNode = _pNode->_prev;
			return it;
		}
	public:
		bool operator==(const iterator& it) const
		{
			return _pNode == it._pNode;
		}
		bool operator!=(const iterator& it) const
		{
			return _pNode != it._pNode;
		}
	public:
		pNode getpNode()
		{
			return _pNode;
		}
	private:
		pNode _pNode;
	};

	
	//容器
	template<class T>
	class list
	{
	public:
		typedef ListNode<T>* pNode;
		typedef iterator<T> iterator;
	public:
		list()
		{
			_createHead();
		}
		list(int n, T data = T())
		{
			_createHead();
			for (int i = 0; i < n; i++)
				push_back(data);
		}
		list(T* first, T* last)
		{
			_createHead();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		list(iterator first, iterator last)
		{
			_createHead();
			while (first != last)
			{
				push_back(first.getpNode()->_data);
				++first;
			}
		}
		~list()
		{
			clear();
			delete _Head;
			_Head = nullptr;
		}
	public:
		iterator begin()
		{
			return iterator(_Head->_next);
		}
		iterator end()
		{
			return iterator(_Head);
		}
	public:
		void push_back(const T& data)
		{
			insert(end(), data);
		}
		void push_front(const T& data)
		{
			insert(begin(), data);
		}
		void pop_back()
		{
			erase(--end());
		}
		void pop_front()
		{
			erase(begin());
		}
	public:
		iterator insert(iterator it, T data)
		{
			pNode s = new ListNode<T>(data);
			pNode p = it.getpNode();

			s->_next = p;
			s->_prev = p->_prev;
			s->_prev->_next = s;
			s->_next->_prev = s;

			return iterator(s);
		}
		iterator erase(iterator it)
		{
			pNode p = it.getpNode();
			it = iterator(p->_next);

			p->_prev->_next = p->_next;
			p->_next->_prev = p->_prev;
			delete p;
			p = nullptr;

			return it;
		}
	public:
		void clear()
		{
			while (begin() != end())
				pop_front();
		}
		void swap(list<T> lt)
		{
			std::swap(_Head, lt._Head);
		}
	protected:
		void _createHead()
		{
			_Head = new ListNode<T>;
			_Head->_next = _Head->_prev = _Head;
		}
	private:
		pNode _Head;
	};
}




















//namespace mylist
//{
//	//list节点类型
//	template<class T>
//
//	struct ListNode
//	{
//		ListNode(const T& data = T()) : _prev(nullptr), _next(nullptr), _data(data){}
//		
//		ListNode<T> *_prev;
//		ListNode<T> *_next;
//		T _data;
//	};
//	//容器类
//	template<class T>
//	class list
//	{
//	public:
//		//迭代器类
//		class iterator
//		{
//		public:
//			//构造方法
//			iterator(ListNode<T> *pNode = nullptr) : _pNode(pNode){}
//			//拷贝构造方法
//			iterator(const iterator &it) : _pNode(it._pNode){}
//			//赋值运算符重载
//			iterator& operator=(const iterator& it)
//			{
//				if (_pNode != it->_pNode)
//				{
//					_pNode = it->_pNode;
//				}
//				return *this;
//			}
//			//解引用运算符重载
//			T& operator*()
//			{
//				return _pNode->_date;
//			}
//			T* operator->()
//			{
//				return &(operator*());
//			}
//			// ++/--运算符重载
//			iterator& operator++()
//			{
//				_pNode = _pNode->_next;
//				return *this;
//			}
//			iterator operator++(int)
//			{
//				//iterator it(*this);
//				iterator it = *this;
//				_pNode = _pNode->_next;
//				return it;
//			}
//			iterator& operator--()
//			{
//				_pNode = _pNode->_prev;
//				return *this;
//			}
//			iterator operator--(int)
//			{
//				iterator it = *this;
//				_pNode = _pNode->_next;
//				return it;
//			}
//			//逻辑运算符重载
//			bool operator==(const iterator& it)
//			{
//				return _pNode == it->_pNode;
//			}
//			bool operator!=(const iterator& it)
//			{
//				return _pNode != it->_pNode;
//			}
//			//访问_pNode
//			ListNode<T>* p()
//			{
//				return _pNode;
//			}
//		private:
//			//迭代器包含一个指向节点类型的指针
//			ListNode<T> *_pNode;
//		};
//
//
//		//申请节点函数
//		ListNode<T>* _ByeNode(T data, ListNode<T> * prev = nullptr, ListNode<T> *next = nullptr)
//		{
//			ListNode<T> *node = new ListNode<T>(data);
//			assert(node != NULL);
//
//			node->_prev = prev != nullptr ? prev : node;
//			node->_next = next != nullptr ? next : node;
//			node->_data = data;
//			return node;
//		}
//		//list无参构造函数
//		list() : _size(0)
//		{
//			_Head = _ByeNode(0);
//		}
//		//n个value的构造方法
//		list(int n, const T& value = T()) : _size(n)
//		{
//			_Head = _ByeNode(0);
//			for (int i = 0; i < n; ++i)
//				push_back(value);
//		}
//		//区间构造方法
//		list(T* first, T* last) : _size(0)
//		{
//			_Head = _ByeNode(0);
//			while (first != last)
//			{
//				push_back(*first);
//				++first;
//			}
//		}
//		list(iterator first, iterator last) : _size(0)
//		{
//			_Head = _ByeNode(0);
//			while (first != last)
//			{
//				push_back(*first);
//				++_size;
//				++first;
//			}
//		}
//		//拷贝构造方法
//		list(const list<T>& l)
//		{
//			_Head = _ByeNode(0);
//			_size = l._size;
//			list<T> temp(l.begin(), l.end());
//			this->swap(temp);
//		}
//		////析构函数
//		//~list()
//		//{
//		//	clear();
//		//	delete _Head;
//		//	_Head = nullptr;
//		//}
//		//赋值运算符重载
//		list<T>& operator=(const list<T> l)
//		{
//			_size = l._size;
//			list<T> temp(l.begin(), l.end());
//			this->swap(temp);
//		}
//		
//
//		//list的begin()
//		iterator begin()
//		{
//			return iterator(_Head->_next);
//		}
//		//list的end()
//		iterator end()
//		{
//			return iterator(_Head);
//		}
//		//查看list信息
//		size_t size() const
//		{
//			return _size;
//		}
//		bool empty() const
//		{
//			return _size == 0;
//		}
//		T& front()
//		{
//			return _Head->_next->_date;
//		}
//		T& back()
//		{
//			return _Head->_prev->_date;
//		}
//		//头尾插删
//		void push_back(const T& data)
//		{
//			insert(end(), data);
//		}
//		void push_front(const T& data)
//		{
//			insert(begin(), data);
//		}
//		void pop_back()
//		{
//			erase(--end());
//		}
//		void pop_front()
//		{
//			erase(begin());
//		}
//		//插入节点
//		iterator insert(iterator pos, const T& data)
//		{
//			ListNode<T> *pNode = _ByeNode(data, pos.p()->_prev,pos.p());
//			pos.p()->_prev = pNode;
//			--pos;
//			pos.p()->_prev->_next = pos.p();
//			++_size;
//			return pos;
//		}
//		//删除节点
//		iterator erase(iterator pos)
//		{
//			ListNode<T> *pNode = pos.p();
//			++pos;
//			pNode->_prev->_next = pNode->_next;
//			pNode->_next->_prev = pNode->_prev;
//			delete pNode;
//			--_size;
//			return pos;
//		}
//		//clear()
//		void clear()
//		{
//			iterator pos = begin();
//			while (pos != end())
//			{
//				pos = erase(pos);
//			}
//		}
//		//swap()
//		void swap(list<T>& l)
//		{
//			ListNode<T> *pNode = l->_Head;
//			l->_Head = _Head;
//			_Head = pNode;
//		}
//
//	private:
//		ListNode<T> *_Head;
//		size_t _size;
//	};
//}








#endif //_LIST_H_