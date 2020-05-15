#define _CRT_SECURE_NO_WARNINGS 1



#include"tree.h"
#include"assistqueue.h"
#include"assiststack.h"


//��ʼ����
void TreeInit(Tree * pt)
{
	assert(pt != NULL);
	pt->root = NULL;
}


//���������
void TreeCreate(Tree * pt)
{
	assert(pt != NULL);
	pt->root = TreeCreate_before();
}
//ǰ��������������
TreeNode * TreeCreate_before()
{
	TNDataType ch = '0';
	scanf("%c", &ch);
	if (ch == '#')
		return NULL;
	else
	{
		//Ϊ�˽ڵ�����ռ䣬����������data
		TreeNode * node = (TreeNode *)malloc(sizeof(TreeNode));
		assert(node != NULL);
		node->data = ch;
		//����������
		node->leftChild = TreeCreate_before();
		//����������
		node->rightChild = TreeCreate_before();

		return node;
	}
}


//ʹ���ַ������������
void TreeCreate_str(Tree * pt, char * str)
{
	assert(pt != NULL);
	assert(str != NULL);
	int index = 0; //��ǵ�ǰӦ�����ַ��±�
	pt->root = TreeCreate_str_before(str, &index);
}
//ʹ���ַ���ǰ��������������
TreeNode * TreeCreate_str_before(char * str, int * pindex)
{
	if (str[*pindex] == '#')
		return NULL;
	else
	{
		//Ϊ�˽ڵ�����ռ䣬����������data
		TreeNode * node = (TreeNode *)malloc(sizeof(TreeNode));
		assert(node != NULL);
		node->data = str[*pindex];
		//����������
		(*pindex)++;
		node->leftChild = TreeCreate_str_before(str, pindex);
		//����������
		(*pindex)++;
		node->rightChild = TreeCreate_str_before(str, pindex);

		return node;
	}
}


//�ݻٶ�����
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




//���������
void TreeBeforeOrder(Tree * pt)
{
	assert(pt != NULL);
	printf("VLR:");
	Order_before(pt->root);
	printf("\n");
}
//����ݹ�
void Order_before(TreeNode * ptn)
{
	if (ptn != NULL)
	{
		printf("%c ", ptn->data);  //������˽ڵ�����
		Order_before(ptn->leftChild);  //����������
		Order_before(ptn->rightChild);  //����������
	}
	
}


//���������
void TreeBetweenOrder(Tree * pt)
{
	assert(pt != NULL);
	printf("LVR:");
	Order_between(pt->root);
	printf("\n");
}
//����ݹ�
void Order_between(TreeNode * ptn)
{
	if (ptn != NULL)
	{
		Order_between(ptn->leftChild);  //����������
		printf("%c ", ptn->data);  //����˽ڵ�
		Order_between(ptn->rightChild);  //����������
	}
}


//���������
void TreeBehindOrder(Tree * pt)
{
	assert(pt != NULL);
	printf("LRV:");
	Order_behind(pt->root);
	printf("\n");
}
//����ݹ�
void Order_behind(TreeNode * ptn)
{
	if (ptn != NULL)
	{
		Order_behind(ptn->leftChild);  //����������
		Order_behind(ptn->rightChild);  //����������
		printf("%c ", ptn->data);  //����˽ڵ�
	}
}



//��α���
void TreeLevelOrder(Tree * pt)
{
	assert(pt != NULL);
	//���첢��ʼ������
	LinkQueue assistQueue ;
	LinkQueueInit(&assistQueue);
	//��������Ϊ�յ�����£����
	if (pt->root != NULL)
		LinkQueuePush(&assistQueue, pt->root);
	printf("Level:");
	//�������У��������ǰ�ڵ㣬���������Һ��Ӳ�Ϊ��ʱ��ӣ�Ȼ�󽫴˽ڵ����
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
	//�ݻٶ���
	LinkQueueDestory(&assistQueue);
}



//��ڵ����
int TreeNodeSize(Tree * pt)
{
	assert(pt != NULL);
	return Order_Size(pt->root);
}
//���������ڵ����
int Order_Size(TreeNode * ptn)
{
	if (ptn == NULL)
		return 0;
	else
		//�ڴ˽ڵ㲻Ϊ�յ�����£������������ڵ�������������ڵ������1
		return 1 + Order_Size(ptn->leftChild) + Order_Size(ptn->rightChild);   
}



//��Ҷ�ӽڵ����
int TreeLeafSize(Tree * pt)
{
	assert(pt != NULL);
	int count = 0;
	if (pt->root != NULL)
		Order_LeafSize(pt->root, &count);
	return count;
}
//���������Ҷ�ӽڵ����
void Order_LeafSize(TreeNode * ptn, int * pcount)
{
	//������Һ��Ӷ�Ϊ�գ���˽ڵ�ΪҶ�ӽڵ㣬count++
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



//���������
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
		////�ڴ˽ڵ㲻Ϊ�յ�����£���������������������Ƚϴ�ֵ��1
		return 1 + max(Order_LevelSize(ptn->leftChild),Order_LevelSize(ptn->rightChild));
}


//����Ԫ��
TreeNode * TreeFind(Tree * pt, TNDataType x)
{
	assert(pt != NULL);
	return Order_Find(pt->root, x);
}
//�����������
TreeNode * Order_Find(TreeNode * ptn, TNDataType x)
{
	//����˽ڵ�Ϊ�ջ��ߴ˽ڵ�dataΪx�����ش˽ڵ�
	if (ptn == NULL || ptn->data == x)
		return ptn;
	else
	{
		//�����������ң��ҵ��˾ͷ���û�ҵ��ͷ������������ҽ��
		TreeNode * node = Order_Find(ptn->leftChild, x);
		if (node != NULL)
			return node;
		else
			return Order_Find(ptn->rightChild, x);
	}
}


//���Ҹ��ڵ�
TreeNode * TreeFindFather(Tree * pt, TNDataType x)
{
	assert(pt != NULL);
	if (pt->root->data == x)
		return NULL;
	else
		return Order_FindFather(pt->root, x);
}
//�����������
TreeNode * Order_FindFather(TreeNode * ptn, TNDataType x)
{
	//����˽ڵ�Ϊ�ջ�dataΪx������NULL
	if (ptn == NULL || ptn->data == x)
	{
		return NULL;
	}
	//������ӻ��Һ���dataֵ����x�����ش˽ڵ�
	else if ((ptn->leftChild != NULL && ptn->leftChild->data == x)|| (ptn->rightChild != NULL && ptn->rightChild->data == x))
	{
		return ptn;
	}
	else
	{
		//�������������ң��ҵ����أ��Ҳ�����������������
		TreeNode * node = Order_FindFather(ptn->leftChild, x);
		if (node != NULL)
			return node;
		else
			return Order_FindFather(ptn->rightChild, x);
	}
}


//������
void TreeCopy(Tree * newTree, Tree * pt)
{
	assert(pt != NULL);
	assert(newTree != NULL);
	newTree->root = Order_Copy(pt->root);
}
//�����������
TreeNode * Order_Copy(TreeNode * ptn)
{
	if (ptn == NULL)
	{
		return NULL;
	}
	else
	{
		//�ȴ����˽ڵ㣬����dataֵ���ƹ���
		TreeNode * newNode = (TreeNode *)malloc(sizeof(TreeNode));
		newNode->data = ptn->data;
		//����������
		newNode->leftChild = Order_Copy(ptn->leftChild);
		//����������
		newNode->rightChild = Order_Copy(ptn->rightChild);
		return newNode;
	}
}



//�ж��������Ƿ���ͬ
bool TreeEqual(Tree * pt1, Tree * pt2)
{
	assert(pt1 != NULL);
	assert(pt2 != NULL);
	return Order_Equal(pt1->root, pt2->root);
}
//��������ж�
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




//�ǵݹ��������
void TreeBeforeOrder_S(Tree* pt)
{
	assert(pt != NULL);
	//���첢��ʼ��ջ
	Stack assistStack;
	StackInit(&assistStack);
	//�����������,��ջ
	if (pt->root != NULL)
	{
		StackPush(&assistStack, pt->root, 'x');
		printf("VLR: ");
		//ջ��Ԫ�س�ջ�����,���ӻ��Һ��Ӳ�Ϊ��ʱ,�����Һ���,��������
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


//�ǵݹ��������
void TreeBetweenOrder_S(Tree* pt)
{
	assert(pt != NULL);
	//���첢��ʼ��ջ
	Stack assistStack;
	StackInit(&assistStack);
	//�����������,��ջ
	if (pt->root != NULL)
	{
		StackPush(&assistStack, pt->root, 'x');
		printf("LVR: ");
		//x�������Ҷ�δ���ʣ�flagΪx�ͷ����󲢽�flag��Ϊl
		//l�����������flagΪl�Ƚ��˽ڵ��ջ��������ٷ�����
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


//�ǵݹ�������
void TreeBehindOrder_S(Tree* pt)
{
	assert(pt != NULL);
	//���첢��ʼ��ջ
	Stack assistStack;
	StackInit(&assistStack);
	//�����������,��ջ
	if (pt->root != NULL)
	{
		StackPush(&assistStack, pt->root, 'x');
		printf("LRV: ");
		//x�������Ҷ�δ���ʣ�flagΪx�ͷ����󲢽�flag��Ϊl
		//l�����������flagΪl�ͷ����Ҳ���flag��Ϊr
		//r�������Ҷ������ˣ�flagΪr��ֱ�ӽ��˽ڵ��ջ�����
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







