#ifndef _RBTREE_H_
#define _RBTREE_H_


#include"common.h"

enum Color
{
	RED,
	BLACK
};

template<class T>
class RBTree;

template<class T>
class RBNode
{
	friend class RBTree<T>;
public:
	RBNode(T value = T(), RBNode<T>* parent = nullptr, Color color = RED)
		: leftchild(nullptr), rightchild(nullptr), parent(nullptr), value(value), color(color)
	{}
private:
	RBNode<T>* leftchild;
	RBNode<T>* rightchild;
	RBNode<T>* parent;
	T value;
	Color color;
};

template<class T>
class RBTree
{
public:
	template<class T>
	class iterator
	{
	private:
		RBNode<T>* 
	};
public:
	RBTree() : NUL(ByeNode())
	{
		NUL->leftchild = NUL->rightchild = NUL->parent = nullptr;
		NUL->color = BLACK;
		root = NUL;
	}
public:
	void insert(T& value)
	{
		if (root == NUL)
		{
			root = ByeNode(value);
			root->color = BLACK;
			return;
		}

		RBNode<T>* t = root;
		RBNode<T>* pt = nullptr;
		while (t != NUL)
		{
			pt = t;
			if (value < t->value)
				t = t->leftchild;
			else
				t = t->rightchild;
		}
		if (value < pt->value)
			pt->leftchild = t = ByeNode(value, pt);
		else
			pt->rightchild = t = ByeNode(value, pt);

		Adjust(t);
	}

	void show()
	{
		show(root);
		cout << endl;
	}
	void show(RBNode<T>* node)
	{
		if (node != NUL)
		{
			show(node->leftchild);
			cout << node->value << " ";
			show(node->rightchild);
		}
	}
protected:
	RBNode<T>* ByeNode(T value = T(), RBNode<T>* parent = nullptr)
	{
		RBNode<T>* node = new RBNode<T>(value, parent);
		node->leftchild = node->rightchild = NUL;
		node->parent = (parent == nullptr ? NUL : parent);
		return node;
	}
	void Adjust(RBNode<T>* node)
	{
		if (node->parent->color == BLACK)
			return;
		RBNode<T>* pnode = node->parent;
		RBNode<T>* gnode = pnode->parent;
		if (pnode == gnode->leftchild)
		{
			int flag = 0;
			if (gnode->rightchild->color == RED && gnode->parent->color == RED)
				flag = 1;
			if (node == pnode->leftchild)
				RotateR(gnode);//ÓÒµ¥Ðý£»
			else
				RotateLR(gnode);
			if (flag)
				Adjust(gnode);
			root->color = BLACK;
		}
		else
		{
			int flag = 0;
			if (gnode->leftchild->color == RED && gnode->parent->color == RED)
				flag = 1;
			if (node == pnode->rightchild)
				RotateL(gnode);
			else
				RotateRL(gnode);
			if (flag)
				Adjust(pnode);
			root->color = BLACK;
		}
	}
protected:
	void RotateR(RBNode<T>* gnode)
	{
		RBNode<T>* pnode = gnode->leftchild;

		if (gnode == gnode->parent->leftchild)
		{
			gnode->parent->leftchild = pnode;
			pnode->parent = gnode->parent;
		}
		else
		{
			gnode->parent->rightchild = pnode;
			pnode->parent = gnode->parent;
		}

		if (root == gnode)
			root = pnode;

		gnode->leftchild = pnode->rightchild;
		gnode->leftchild->parent = gnode;

		pnode->rightchild = gnode;
		pnode->rightchild->parent = pnode;

		if (gnode->rightchild->color == BLACK)
		{
			pnode->color = BLACK;
		    gnode->color = RED;
		}
		else
		{
			pnode->leftchild->color = BLACK;
		}
	}
	void RotateLR(RBNode<T>* gnode)
	{
		RBNode<T>* pnode = gnode->leftchild;
		
		gnode->leftchild = pnode->rightchild;
		gnode->leftchild->parent = gnode;

		pnode->rightchild = gnode->leftchild->leftchild;
		pnode->rightchild->parent = pnode;

		gnode->leftchild->leftchild = pnode;
		gnode->leftchild->leftchild->parent = gnode->leftchild;

		RotateR(gnode);
	}
	void RotateL(RBNode<T>* gnode)
	{
		RBNode<T>* pnode = gnode->rightchild;

		if (gnode == gnode->parent->rightchild)
		{
			gnode->parent->rightchild = pnode;
			pnode->parent = gnode->parent;
		}
		else
		{
			gnode->parent->leftchild = pnode;
			pnode->parent = gnode->parent;
		}

		if (root == gnode)
			root = pnode;

		gnode->rightchild = pnode->leftchild;
		gnode->rightchild->parent = gnode;

		pnode->leftchild = gnode;
		pnode->leftchild->parent = pnode;

		if (gnode->leftchild->color == BLACK)
		{
			pnode->color = BLACK;
			gnode->color = RED;
		}
		else
		{
			pnode->rightchild->color = BLACK;
		}
	}
	void RotateRL(RBNode<T>* gnode)
	{
		RBNode<T>* pnode = gnode->rightchild;

		gnode->rightchild = pnode->leftchild;
		gnode->rightchild->parent = gnode;

		pnode->leftchild = gnode->rightchild->rightchild;
		pnode->leftchild->parent = pnode;

		gnode->rightchild->rightchild = pnode;
		gnode->rightchild->rightchild->parent = gnode->rightchild;

		RotateL(gnode);
	}
private:
	RBNode<T>* root;
	RBNode<T>* NUL;
};



#endif