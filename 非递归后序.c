//�ǵݹ�������
void TreeBehindOrder_S(Tree* pt)
{
	assert(pt != NULL);
	//���첢��ʼ��ջ
	Stack assistStack;
	StackInit(&assistStack);
	//�����������,��ջ
	if (pt->root != NULL)
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