//非递归中序遍历
void TreeBetweenOrder_S(Tree* pt)
{
	assert(pt != NULL);
	//构造并初始化栈
	Stack assistStack;
	StackInit(&assistStack);
	//如果树根不空,入栈
	if (pt->root != NULL)
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