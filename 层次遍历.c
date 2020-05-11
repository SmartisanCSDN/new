//��α���
void TreeLevelOrder(Tree * pt)
{
	assert(pt != NULL);
	//���첢��ʼ������
	LinkQueue assistQueue;
	LinkQueueInit(&assistQueue);
	//��������Ϊ�յ�����£����
	if (pt->root != NULL)
		LinkQueuePush(&assistQueue, pt->root);
	printf("Level:");
	//�������У��������ǰ�ڵ㣬���������Һ��Ӳ�Ϊ��ʱ��ӣ�Ȼ�󽫴˽ڵ����
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
	//�ݻٶ���
	LinkQueueDestory(&assistQueue);
}