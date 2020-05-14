//非递归先序遍历
void TreeBeforeOrder_S(Tree* pt)
{
	assert(pt != NULL);
	//构造并初始化栈
	Stack assistStack;
	StackInit(&assistStack);
	//如果树根不空,入栈
	if (pt->root != NULL)
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