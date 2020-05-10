//���������
void TreeCreate(Tree * pt)
{
	assert(pt != NULL);
	pt->root = TreeCreate_before();
}


//ǰ��������������
TreeNode * TreeCreate_before()
{
	TNDataType ch = '0';
	scanf("%c", &ch);
	if (ch == '#')
		return NULL;
	else
	{
		//Ϊ�˽ڵ�����ռ䣬����������data
		TreeNode * node = (TreeNode *)malloc(sizeof(TreeNode));
		assert(node != NULL);
		node->data = ch;
		//����������
		node->liftChild = TreeCreate_before();
		//����������
		node->rightChild = TreeCreate_before();

		return node;
	}
}