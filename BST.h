#ifndef _BST_H_
#define _BST_H_

#include"common.h"


template<class T>
class BST;

template<class T>
class BSTNode
{
public:
	friend BST<T>;
	BSTNode(T value = T(), BSTNode<T> * left = nullptr, BSTNode<T> * right = nullptr)
		:value(value), left(left), right(right)
	{}
	const T& getvalue()
	{
		return value;
	}
private:
	T value;
	BSTNode<T> * left;
	BSTNode<T> * right;
};



template<class T>
class BST
{
public:
	BST() : root(nullptr)
	{}
	BST(T* begin, T* end) : root(nullptr)
	{
		while (begin != NULL && begin < end)
		{
			insert(*begin);
			++begin;
		}
	}

	~BST()
	{
		clear();
	}
public:
	void show()
	{
		show(root);
		cout << endl;
	}
	void insert(T& value)
	{
		insert(root, value);
	}
	BSTNode<T>* find(T& value)
	{
		return find(root, value);
	}
	bool erase(T& value)
	{
		return erase(root, value);
	}
	void clear()
	{
		clear(root);
	}
protected:
	void show(BSTNode<T>* &node)
	{
		if (node != NULL)
		{
			show(node->left);
			cout << node->getvalue() << " ";
			show(node->right);
		}
	}
	void insert(BSTNode<T>* &node, T value)
	{
		if (node == nullptr)
			node = new BSTNode<T>(value);
		else if (node->value > value)
			insert(node->left, value);
		else
			insert(node->right, value);
	}
	BSTNode<T>* find(BSTNode<T> * node, T & value)
	{
		if (node == nullptr)
			return nullptr;
		else if (value == node->value)
			return node;
		else if (value < node->value)
			return find(node->left, value);
		else
			return find(node->right, value);
	}
	bool erase(BSTNode<T>* &node, T & value)
	{
		if (node == nullptr)
			return false;
		else if (value < node->value)
			return erase(node->left, value);
		else if (value > node->value)
			return erase(node->right, value);
		else
		{
			if (node->left == nullptr || node->right == nullptr)
			{
				BSTNode<T>* child = nullptr;
				if (node->left != nullptr)
					BSTNode<T>* child = node->left;
				if (node->right != nullptr)
					BSTNode<T>* child = node->right;
				delete node;
				node = child;
			}
			else
			{
				BSTNode<T>* lchild = node->left;
				BSTNode<T>* rchild = node->right;
				delete node;
				node = rchild;
				BSTNode<T>* place = node;
				while (place->left != nullptr)
					place = place->left;
				place->left = lchild;
			}
			return true;
		}
	}
	void clear(BSTNode<T>* &node)
	{
		if (node != nullptr)
		{
			clear(node->left);
			clear(node->right);
			delete node;
			node = nullptr;
		}
	}
private:
	BSTNode<T> * root;
};





#endif // _BST_H_