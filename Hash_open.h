#ifndef _HASH_H_
#define _HASH_H_

#include"common.h"
#include<vector>


template<class T>
class Hash_Table;

template<class T>
class HashNode
{
	friend class Hash_Table<T>;
public:
	HashNode(T value = T(), HashNode<T>* link = nullptr)
		: _value(value), _link(link)
	{}
private:
	T _value;
	HashNode<T>* _link;
};

template<class T>
class Hash_Table
{
public:
	Hash_Table(int length = 5)
	{
		_length = length > 0 ? length : 5;
		_table.resize(length);
		for (size_t i = 1; i < _length; ++i)
			_table[i] = nullptr;
	}
	~Hash_Table()
	{
		clear();
	}
public:
	bool empty()
	{
		for (size_t i = 0; i < _length; ++i)
		{
			if (_table[i] != nullptr)
				return false;
		}
		return true;
	}
	size_t size()
	{
		size_t count = 0;
		for (size_t i = 0; i < _length; ++i)
		{
			HashNode<T>* node = _table[i];
			while (node != nullptr)
			{
				++count;
				node = node->_link;
			}
		}
		return count;
	}
public:
	void insert(T& value)
	{
		int index = value % _length;
		HashNode<T>* newnode = new HashNode<T>(value, _table[index]);
		_table[index] = newnode;
	}
	void erase(T value)
	{
		HashNode<T>* node = find(value);
		if (node != nullptr)
			erase(node);
	}
	void erase(HashNode<T>* node)
	{
		if (node != nullptr)
		{
			int index = node->_value % _length;
			if (_table[index] == node)
			{
				_table[index] = node->_link;
				delete node;
			}
			else
			{
				HashNode<T>* prev = _table[index];
				while (prev != nullptr && prev->_link != node)
					prev = prev->_link;
				prev->_link = node->_link;
				delete node;
			}
		}
	}
	HashNode<T>* find(T value)
	{
		int index = value % _length;
		HashNode<T>* node = _table[index];
		while (node != nullptr && node->_value != value)
			node = node->_link;
		return node;
	}
public:
	void swap(Hash_Table<T>& ht)
	{
		size_t temp_len = _length;
		_length = ht._length;
		ht._length = temp_len;

		vector<HashNode<T>*> temp_t = _table;
		_table = ht._table;
		ht._table = temp_t;
	}
	void clear()
	{
		for (size_t i = 0; i < _length; ++i)
		{
			distory(_table[i]);
		}
	}
protected:
	void distory(HashNode<T>*& node)
	{
		if (node != nullptr)
		{
			distory(node->_link);
			delete node;
			node = nullptr;
		}
	}
private:
	vector<HashNode<T>*> _table;
	size_t _length;
};





#endif  //_HASH_H_