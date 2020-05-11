//层次遍历
void TreeLevelOrder(Tree * pt)
{
	assert(pt != NULL);
	//构造并初始化队列
	LinkQueue assistQueue;
	LinkQueueInit(&assistQueue);
	//在树根不为空的情况下，入队
	if (pt->root != NULL)
		LinkQueuePush(&assistQueue, pt->root);
	printf("Level:");
	//遍历队列，先输出当前节点，并且其左右孩子不为空时入队，然后将此节点出队
	while ((&assistQueue)->head != NULL)
	{
		printf("%c ", LinkQueueHead(&assistQueue)->data);
		if (LinkQueueHead(&assistQueue)->liftChild != NULL)
			LinkQueuePush(&assistQueue, LinkQueueHead(&assistQueue)->liftChild);
		if (LinkQueueHead(&assistQueue)->rightChild != NULL)
			LinkQueuePush(&assistQueue, LinkQueueHead(&assistQueue)->rightChild);
		LinkQueuePop(&assistQueue);
	}
	printf("\n");
	//摧毁队列
	LinkQueueDestory(&assistQueue);
}