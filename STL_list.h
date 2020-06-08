#ifndef _LIST_H_
#define _LIST_H_


#include<iostream>

using namespace std;


namespace mylist
{
	//list�ڵ�����
	template<class T>
	struct ListNode
	{
		//���캯����dataĬ��ΪT���͵�0ֵ
		ListNode(const T& data = T()) : _prev(nullptr), _next(nullptr), _data(data){}
		ListNode<T> *_prev;
		ListNode<T> *_next;
		T _date;
	};
	//������
	template<class T>
	class list
	{
	public:
		
		//����ڵ㺯��
		ListNode<T>* _ByeNode(T data, ListNode<T> * prev = nullptr, ListNode<T> *next = nullptr)
		{
			ListNode<T> *node = (ListNode<T>*)malloc(sizeof(ListNode<T>));
			node->_prev = prev != nullptr ? prev : node;
			node->_next = next != nullptr ? next : node;
			node->_date = data;
			return node;
		}
		//list���캯��
		list() : _size(0)
		{
			_Head = _ByeNode(0);
		}
		//��������
		class iterator
		{
		public:
			//���췽��
			iterator(ListNode<T> *pNode) : _pNode(pNode){}

		private:
			//����������һ��ָ��ڵ����͵�ָ��
			ListNode<T> *_pNode;
		};
		//list��begin()
		iterator begin()
		{
			return iterator(_Head->_next);
		}
		//list��end()
		{
			return iterator(_Head);
		}
	private:
		ListNode<T> *_Head;
		size_t _size;
	};
}








#endif //_LIST_H_