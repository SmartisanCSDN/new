//�ǵݹ��������
void TreeBeforeOrder_S(Tree* pt)
{
	assert(pt != NULL);
	//���첢��ʼ��ջ
	Stack assistStack;
	StackInit(&assistStack);
	//�����������,��ջ
	if (pt->root != NULL)
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