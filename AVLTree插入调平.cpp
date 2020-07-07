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