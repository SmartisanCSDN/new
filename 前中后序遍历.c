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
		Order_before(ptn->liftChild);  //遍历左子树
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
		Order_between(ptn->liftChild);  //遍历左子树
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
		Order_behind(ptn->liftChild);  //遍历左子树
		Order_behind(ptn->rightChild);  //遍历右子树
		printf("%c ", ptn->data);  //输出此节点
	}
}