//非递归后序遍历
void TreeBehindOrder_S(Tree* pt)
{
	assert(pt != NULL);
	//构造并初始化栈
	Stack assistStack;
	StackInit(&assistStack);
	//如果树根不空,入栈
	if (pt->root != NULL)
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