#ifndef _AVLTREE_H_
#define _AVLTREE_H_

#include<stack>
#include"common.h"


template<class T>
class AVLTree;

template<class T>
class AVLNode
{
	friend class AVLTree<T>;
public:
	AVLNode(T& value = value(), AVLNode<T>* leftchild = nullptr, AVLNode<T>* rightchild = nullptr)
		: value(value), leftchild(leftchild), rightchild(rightchild)
	{}
private:
	T value;
	AVLNode<T>* leftchild;
	AVLNode<T>* rightchild;
	int bf;   //平衡因子
};


template<class T>
class AVLTree
{
public:
	AVLTree() : root(nullptr)
	{}
public:
	void insert(T& value)
	{
		if (root == nullptr)
			root = new AVLNode<T>(value);
		else
		{
			//先找插入位置插入，并记录路线。
			stack<AVLNode<T>*> stack;
			AVLNode<T>* t = root;
			while (t != nullptr)
			{
				stack.push(t);
				if (value < t->value)
					t = t->leftchild;
				else
					t = t->rightchild;
			}
			AVLNode<T>* pt = stack.top();
			if (value < pt->value)
				pt->leftchild = t = new AVLNode<T>(value);
			else
				pt->rightchild = t = new AVLNode<T>(value);

			while (!stack.empty())
			{
				pt = stack.top();
				stack.pop();
				if (t == pt->leftchild)
					--(pt->bf);
				else
					++(pt->bf);

				if (pt->bf == 0)
					break;
				else if (pt->bf == -1 || pt->bf == 1)
					t = pt;
				else
				{
					if (pt->bf < 0)
					{
						if (t->bf < 0)
							//cout << "R" << endl;
							RotateR(pt);
						else
							//cout << "LR" << endl;
							RotateLR(pt);
					}
					else
					{
						if (t->bf > 0)
							//cout << "L" << endl;
							RotateL(pt);
						else
							//cout << "RL" << endl;
							RotateRL(pt);
					}
					break;
				}
			}
			if (stack.empty())
				root = pt;
			else
			{
				AVLNode<T>* ppt = stack.top();
				if (pt->value < ppt->value)
					ppt->leftchild = pt;
				else
					ppt->rightchild = pt;
			}
		}
	}
protected:
	void RotateR(AVLNode<T>*& pt)
	{
		AVLNode<T>* R = pt;
		pt = R->leftchild;
		R->leftchild = pt->rightchild;
		pt->rightchild = R;

		pt->bf = R->bf = 0;
	}
	void RotateLR(AVLNode<T>*& pt)
	{
		AVLNode<T>* L = pt->leftchild;
		AVLNode<T>* R = pt;

		pt = L->rightchild;

		L->rightchild = pt->leftchild;
		pt->leftchild = L;

		if (pt->bf == -1 || pt->bf == 0)
		{
			L->bf = 0;
		}
		else
		{
			L->bf = -1;
		}

		R->leftchild = pt->rightchild;
		pt->rightchild = R;

		if (pt->bf == 1 || pt->bf == 0)
		{
			R->bf = 0;
		}
		else
		{
			R->bf = 1;
		}

		pt->bf = 0;
	}
	void RotateL(AVLNode<T>*& pt)
	{
		AVLNode<T>* L = pt;
		pt = L->rightchild;
		L->rightchild = pt->leftchild;
		pt->leftchild = L;

		pt->bf = L->bf = 0;
	}
	void RotateRL(AVLNode<T>*& pt)
	{
		AVLNode<T>* L = pt;
		AVLNode<T>* R = pt->rightchild;

		pt = R->leftchild;

		L->rightchild = pt->leftchild;
		pt->leftchild = L;
		if (pt->bf == -1 || pt->bf == 0)
			L->bf = 0;
		else
			L->bf = -1;

		R->leftchild = pt->rightchild;
		pt->rightchild = R;
		if (pt->bf == 1 || pt->bf == 0)
			R->bf = 0;
		else
			R->bf = 1;

		pt->bf = 0;
	}
private:
	AVLNode<T>* root;
};









//template<class T>
//class AVLTree;
//
//template<class T>
//class AVLNode
//{
//public:
//	friend class AVLTree<T>;
//	AVLNode(T& value = T(), AVLNode<T>*  left = nullptr, AVLNode<T>* right = nullptr, int bf = 0)
//		: value(value), left(left), right(right), bf(bf)
//	{}
//private:
//	T value;
//	AVLNode<T> * left;
//	AVLNode<T> * right;
//	int bf;  //平衡因子
//};
//
//
//
//template<class T>
//class AVLTree
//{
//public:
//	AVLTree() : root(nullptr)
//	{}
//public:
//	void insert(T& value);
//protected:
//	void RotateR(AVLNode<T>*& node); 
//	void RotateLR(AVLNode<T>*& node);
//	void RotateL(AVLNode<T>*& node);
//	void RotateRL(AVLNode<T>*& node);
//private:
//	AVLNode<T>* root;
//};
//
//template<class T>
//void AVLTree<T>::insert(T& value)
//{
//	if (root == nullptr)
//		root = new AVLNode<T>(value);
//	else
//	{
//		stack<AVLNode<T>*> stack;
//		AVLNode<T> * newnode = root;
//		while (1)
//		{
//			stack.push(newnode);
//			if (value < newnode->value)
//			{
//				if (newnode->left == nullptr)
//				{
//					newnode->left = new AVLNode<T>(value);
//					newnode = newnode->left;
//					break;
//				}
//				else
//					newnode = newnode->left;
//			}
//			else
//			{
//				if (newnode->right == nullptr)
//				{
//					newnode->right = new AVLNode<T>(value);
//					newnode = newnode->right;
//					break;
//				}
//				else
//					newnode = newnode->right;
//			}	
//		}
//		AVLNode<T>* pt = stack.top();
//		while (!stack.empty())
//		{
//			AVLNode<T>* pt = stack.top();
//			stack.pop();
//			if (newnode == pt->left)
//				--(pt->bf);
//			else
//				++(pt->bf);
//
//			if (pt->bf == 0)
//				break;
//			else if (pt->bf == -1 || pt->bf == 1)
//				newnode = pt;
//			else
//			{
//				if (pt->bf < 0)
//				{
//					if (newnode->bf < 0)
//						RotateR(pt);
//					else
//						RotateLR(pt);
//				}
//				else
//				{
//					if (newnode->bf > 0)
//						RotateL(pt);
//					else
//						RotateRL(pt);
//				}
//				break;
//			}
//		}
//		if (stack.empty())
//			root = pt;
//		else
//		{
//			AVLNode<T>* ppt = stack.top();
//			if (pt->value < ppt->value)
//				ppt->left = pt;
//			else
//				ppt->right = pt;
//		}
//	}
//}
//
//
//template<class T>
//void AVLTree<T>::RotateR(AVLNode<T>*& node)
//{
//	AVLNode<T> * temp = node;
//	node = temp->left;
//	temp->left = node->right;
//	node->right = temp;
//
//	node->bf = temp->bf = 0;
//}
//
//template<class T>
//void AVLTree<T>::RotateLR(AVLNode<T>*& node)
//{
//	////左旋
//	//AVLNode<T>* temp = node->left;
//	//node->left = temp->right;
//	//temp->right = node->left->left;
//	//node->left->left = temp;
//
//	////右旋
//	//temp = node;
//	//node = temp->left;
//	//temp->left = node->right;
//	//node->right = temp;
//
//
//	AVLNode<T>* left = node->left;
//	AVLNode<T>* right = node;
//	node = left->right;
//
//	left->right = node->left;
//	node->left = left;
//
//	if (node->bf == -1 || node->bf == 0)
//		left->bf = 0;
//	else
//		left->bf = -1;
//
//	right->left = node->right;
//	node->right = right;
//
//	if (node->bf == 1 || node->bf == 0)
//		left->bf = 0;
//	else
//		left->bf = 1;
//
//	node->bf = 0;
//}
//
//template<class T>
//void AVLTree<T>::RotateL(AVLNode<T>*& node)
//{
//	AVLNode<T>* temp = node;
//	node = temp->right;
//	temp->right = node->left;
//	node->left = temp;
//
//	node->bf = temp->bf = 0;
//}
//
//template<class T>
//void AVLTree<T>::RotateRL(AVLNode<T>*& node)
//{
//	////右旋
//	//AVLNode<T>* temp = node->right;
//	//node->right = temp->left;
//	//temp->left = node->right->right;
//	//node->right->right = temp;
//
//	////左旋
//	//temp = node;
//	//node = temp->right;
//	//temp->right = node->left;
//	//node->left = temp;
//
//
//	AVLNode<T>* right = node->right;
//	AVLNode<T>* left = node;
//	node = right->left;
//
//	left->right = node->left;
//	node->left = left;
//
//	if (node->bf == -1 || node->bf == 0)
//		left->bf = 0;
//	else
//		left->bf = -1;
//
//	right->left = node->right;
//	node->right = right;
//
//	if (node->bf == 1 || node->bf == 0)
//		left->bf = 0;
//	else
//		left->bf = 1;
//
//	node->bf = 0;
//}

#endif