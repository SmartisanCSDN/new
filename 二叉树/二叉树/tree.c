#define _CRT_SECURE_NO_WARNINGS 1



#include"tree.h"
#include"assistqueue.h"
#include"assiststack.h"


//初始化树
void TreeInit(Tree * pt)
{
	assert(pt != NULL);
	pt->root = NULL;
}


//构造二叉树
void TreeCreate(Tree * pt)
{
	assert(pt != NULL);
	pt->root = TreeCreate_before();
}
//前序遍历构造二叉树
TreeNode * TreeCreate_before()
{
	TNDataType ch = '0';
	scanf("%c", &ch);
	if (ch == '#')
		return NULL;
	else
	{
		//为此节点申请空间，并填入数据data
		TreeNode * node = (TreeNode *)malloc(sizeof(TreeNode));
		assert(node != NULL);
		node->data = ch;
		//建立左子树
		node->leftChild = TreeCreate_before();
		//建立右子树
		node->rightChild = TreeCreate_before();

		return node;
	}
}


//使用字符串构造二叉树
void TreeCreate_str(Tree * pt, char * str)
{
	assert(pt != NULL);
	assert(str != NULL);
	int index = 0; //标记当前应访问字符下标
	pt->root = TreeCreate_str_before(str, &index);
}
//使用字符串前序遍历构造二叉树
TreeNode * TreeCreate_str_before(char * str, int * pindex)
{
	if (str[*pindex] == '#')
		return NULL;
	else
	{
		//为此节点申请空间，并填入数据data
		TreeNode * node = (TreeNode *)malloc(sizeof(TreeNode));
		assert(node != NULL);
		node->data = str[*pindex];
		//建立左子树
		(*pindex)++;
		node->leftChild = TreeCreate_str_before(str, pindex);
		//建立右子树
		(*pindex)++;
		node->rightChild = TreeCreate_str_before(str, pindex);

		return node;
	}
}


//摧毁二叉树
void TreeDestory(Tree * pt)
{
	assert(pt != NULL);
	if (pt->root != NULL);
		TreeDestory_again(&(pt->root));
}
void TreeDestory_again(TreeNode ** pptn)
{
	if ((*pptn)->leftChild != NULL)
		TreeDestory_again(&((*pptn)->leftChild));
	if ((*pptn)->rightChild != NULL)
		TreeDestory_again(&((*pptn)->rightChild));
	free(*pptn);
	*pptn = NULL;
}




//先序遍历法
void TreeBeforeOrder(Tree * pt)
{
	assert(pt != NULL);
	printf("VLR:");
	Order_before(pt->root);
	printf("\n");
}
//先序递归
void Order_before(TreeNode * ptn)
{
	if (ptn != NULL)
	{
		printf("%c ", ptn->data);  //先输出此节点数据
		Order_before(ptn->leftChild);  //遍历左子树
		Order_before(ptn->rightChild);  //遍历右子树
	}
	
}


//中序遍历法
void TreeBetweenOrder(Tree * pt)
{
	assert(pt != NULL);
	printf("LVR:");
	Order_between(pt->root);
	printf("\n");
}
//中序递归
void Order_between(TreeNode * ptn)
{
	if (ptn != NULL)
	{
		Order_between(ptn->leftChild);  //遍历左子树
		printf("%c ", ptn->data);  //输出此节点
		Order_between(ptn->rightChild);  //遍历右子树
	}
}


//后序遍历法
void TreeBehindOrder(Tree * pt)
{
	assert(pt != NULL);
	printf("LRV:");
	Order_behind(pt->root);
	printf("\n");
}
//后序递归
void Order_behind(TreeNode * ptn)
{
	if (ptn != NULL)
	{
		Order_behind(ptn->leftChild);  //遍历左子树
		Order_behind(ptn->rightChild);  //遍历右子树
		printf("%c ", ptn->data);  //输出此节点
	}
}



//层次遍历
void TreeLevelOrder(Tree * pt)
{
	assert(pt != NULL);
	//构造并初始化队列
	LinkQueue assistQueue ;
	LinkQueueInit(&assistQueue);
	//在树根不为空的情况下，入队
	if (pt->root != NULL)
		LinkQueuePush(&assistQueue, pt->root);
	printf("Level:");
	//遍历队列，先输出当前节点，并且其左右孩子不为空时入队，然后将此节点出队
	while ((&assistQueue)->head != NULL)
	{
		printf("%c ", LinkQueueHead(&assistQueue)->data);
		if (LinkQueueHead(&assistQueue)->leftChild != NULL)
			LinkQueuePush(&assistQueue, LinkQueueHead(&assistQueue)->leftChild);
		if (LinkQueueHead(&assistQueue)->rightChild != NULL)
			LinkQueuePush(&assistQueue, LinkQueueHead(&assistQueue)->rightChild);
		LinkQueuePop(&assistQueue);
	}
	printf("\n");
	//摧毁队列
	LinkQueueDestory(&assistQueue);
}



//求节点个数
int TreeNodeSize(Tree * pt)
{
	assert(pt != NULL);
	return Order_Size(pt->root);
}
//先序遍历求节点个数
int Order_Size(TreeNode * ptn)
{
	if (ptn == NULL)
		return 0;
	else
		//在此节点不为空的情况下，返回左子树节点个数加右子树节点个数加1
		return 1 + Order_Size(ptn->leftChild) + Order_Size(ptn->rightChild);   
}



//求叶子节点个数
int TreeLeafSize(Tree * pt)
{
	assert(pt != NULL);
	int count = 0;
	if (pt->root != NULL)
		Order_LeafSize(pt->root, &count);
	return count;
}
//先序遍历求叶子节点个数
void Order_LeafSize(TreeNode * ptn, int * pcount)
{
	//如果左右孩子都为空，则此节点为叶子节点，count++
	if (ptn->leftChild == NULL && ptn->rightChild == NULL)
		(*pcount)++;
	else
	{
		if (ptn->leftChild != NULL)
			Order_LeafSize(ptn->leftChild, pcount);
		if (ptn->rightChild != NULL)
			Order_LeafSize(ptn->rightChild, pcount);
	}
}



//求树的深度
int TreeLevelKSize(Tree * pt)
{
	assert(pt != NULL);
	return Order_LevelSize(pt->root);
}
int Order_LevelSize(TreeNode * ptn)
{
	if (ptn == NULL)
		return 0;
	else
		////在此节点不为空的情况下，返回左子树和右子树深度较大值加1
		return 1 + max(Order_LevelSize(ptn->leftChild),Order_LevelSize(ptn->rightChild));
}


//查找元素
TreeNode * TreeFind(Tree * pt, TNDataType x)
{
	assert(pt != NULL);
	return Order_Find(pt->root, x);
}
//先序遍历查找
TreeNode * Order_Find(TreeNode * ptn, TNDataType x)
{
	//如果此节点为空或者此节点data为x，返回此节点
	if (ptn == NULL || ptn->data == x)
		return ptn;
	else
	{
		//在左子树中找，找到了就返回没找到就返回右子树查找结果
		TreeNode * node = Order_Find(ptn->leftChild, x);
		if (node != NULL)
			return node;
		else
			return Order_Find(ptn->rightChild, x);
	}
}


//查找父节点
TreeNode * TreeFindFather(Tree * pt, TNDataType x)
{
	assert(pt != NULL);
	if (pt->root->data == x)
		return NULL;
	else
		return Order_FindFather(pt->root, x);
}
//先序遍历查找
TreeNode * Order_FindFather(TreeNode * ptn, TNDataType x)
{
	//如果此节点为空或data为x，返回NULL
	if (ptn == NULL || ptn->data == x)
	{
		return NULL;
	}
	//如果左孩子或右孩子data值等于x，返回此节点
	else if ((ptn->leftChild != NULL && ptn->leftChild->data == x)|| (ptn->rightChild != NULL && ptn->rightChild->data == x))
	{
		return ptn;
	}
	else
	{
		//先在左子树中找，找到返回，找不到就在右子树中找
		TreeNode * node = Order_FindFather(ptn->leftChild, x);
		if (node != NULL)
			return node;
		else
			return Order_FindFather(ptn->rightChild, x);
	}
}


//拷贝树
void TreeCopy(Tree * newTree, Tree * pt)
{
	assert(pt != NULL);
	assert(newTree != NULL);
	newTree->root = Order_Copy(pt->root);
}
//先序遍历复制
TreeNode * Order_Copy(TreeNode * ptn)
{
	if (ptn == NULL)
	{
		return NULL;
	}
	else
	{
		//先创建此节点，并把data值复制过来
		TreeNode * newNode = (TreeNode *)malloc(sizeof(TreeNode));
		newNode->data = ptn->data;
		//复制左子树
		newNode->leftChild = Order_Copy(ptn->leftChild);
		//复制右子树
		newNode->rightChild = Order_Copy(ptn->rightChild);
		return newNode;
	}
}



//判断两颗树是否相同
bool TreeEqual(Tree * pt1, Tree * pt2)
{
	assert(pt1 != NULL);
	assert(pt2 != NULL);
	return Order_Equal(pt1->root, pt2->root);
}
//先序遍历判断
bool Order_Equal(TreeNode * ptn1, TreeNode * ptn2)
{
	if (ptn1 == NULL && ptn2 == NULL)
		return true;
	else if (ptn1 == NULL || ptn2 == NULL)
		return false;
	else
	{
		if (ptn1->data != ptn2->data)
			return false;
		else
		{
			if (Order_Equal(ptn1->leftChild, ptn2->leftChild) == false || Order_Equal(ptn1->rightChild, ptn2->rightChild) == false)
				return false;
			else
				return true;
		}
	}
}




//非递归先序遍历
void TreeBeforeOrder_S(Tree* pt)
{
	assert(pt != NULL);
	//构造并初始化栈
	Stack assistStack;
	StackInit(&assistStack);
	//如果树根不空,入栈
	if (pt->root != NULL)
	{
		StackPush(&assistStack, pt->root, 'x');
		printf("VLR: ");
		//栈顶元素出栈并输出,左孩子或右孩子不为空时,先入右孩子,再入左孩子
		while (assistStack.top != NULL)
		{
			TreeNode* node = StackTop(&assistStack);
			printf("%c ", node->data);
			StackPop(&assistStack);
			if (node->rightChild != NULL)
				StackPush(&assistStack, node->rightChild, 'x');
			if (node->leftChild != NULL)
				StackPush(&assistStack, node->leftChild, 'x');
		}
		printf("\n");
		StackDestory(&assistStack);
	}
}


//非递归中序遍历
void TreeBetweenOrder_S(Tree* pt)
{
	assert(pt != NULL);
	//构造并初始化栈
	Stack assistStack;
	StackInit(&assistStack);
	//如果树根不空,入栈
	if (pt->root != NULL)
	{
		StackPush(&assistStack, pt->root, 'x');
		printf("LVR: ");
		//x代表左右都未访问，flag为x就访问左并将flag改为l
		//l代表访问了左，flag为l先将此节点出栈并输出，再访问右
		while (assistStack.top != NULL)
		{
			if (assistStack.top->flag == 'x')
			{
				assistStack.top->flag = 'l';
				if (StackTop(&assistStack)->leftChild != NULL)
					StackPush(&assistStack, StackTop(&assistStack)->leftChild, 'x');
			}
			if (assistStack.top->flag == 'l')
			{
				TreeNode* node = StackTop(&assistStack);
				printf("%c ", node->data);
				StackPop(&assistStack);
				if (node->rightChild != NULL)
					StackPush(&assistStack, node->rightChild, 'x');
			}
		}
		printf("\n");
		StackDestory(&assistStack);
	}
}


//非递归后序遍历
void TreeBehindOrder_S(Tree* pt)
{
	assert(pt != NULL);
	//构造并初始化栈
	Stack assistStack;
	StackInit(&assistStack);
	//如果树根不空,入栈
	if (pt->root != NULL)
	{
		StackPush(&assistStack, pt->root, 'x');
		printf("LRV: ");
		//x代表左右都未访问，flag为x就访问左并将flag改为l
		//l代表访问了左，flag为l就访问右并将flag改为r
		//r代表左右都访问了，flag为r就直接将此节点出栈并输出
		while (assistStack.top != NULL)
		{
			if (assistStack.top->flag == 'x')
			{
				assistStack.top->flag = 'l';
				if (StackTop(&assistStack)->leftChild != NULL)
					StackPush(&assistStack, StackTop(&assistStack)->leftChild, 'x');
			}
			if (assistStack.top->flag == 'l')
			{
				assistStack.top->flag = 'r';
				if (StackTop(&assistStack)->rightChild != NULL)
					StackPush(&assistStack, StackTop(&assistStack)->rightChild, 'x');
			}
			if (assistStack.top->flag == 'r')
			{
				printf("%c ", StackTop(&assistStack)->data);
				StackPop(&assistStack);
			}
		}
		printf("\n");
		StackDestory(&assistStack);
	}
}







