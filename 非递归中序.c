//�ǵݹ��������
void TreeBetweenOrder_S(Tree* pt)
{
	assert(pt != NULL);
	//���첢��ʼ��ջ
	Stack assistStack;
	StackInit(&assistStack);
	//�����������,��ջ
	if (pt->root != NULL)
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