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
		Order_before(ptn->liftChild);  //����������
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
		Order_between(ptn->liftChild);  //����������
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
		Order_behind(ptn->liftChild);  //����������
		Order_behind(ptn->rightChild);  //����������
		printf("%c ", ptn->data);  //����˽ڵ�
	}
}