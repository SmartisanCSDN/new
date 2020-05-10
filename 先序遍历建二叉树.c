//构造二叉树
void TreeCreate(Tree * pt)
{
	assert(pt != NULL);
	pt->root = TreeCreate_before();
}


//前序遍历构造二叉树
TreeNode * TreeCreate_before()
{
	TNDataType ch = '0';
	scanf("%c", &ch);
	if (ch == '#')
		return NULL;
	else
	{
		//为此节点申请空间，并填入数据data
		TreeNode * node = (TreeNode *)malloc(sizeof(TreeNode));
		assert(node != NULL);
		node->data = ch;
		//建立左子树
		node->liftChild = TreeCreate_before();
		//建立右子树
		node->rightChild = TreeCreate_before();

		return node;
	}
}