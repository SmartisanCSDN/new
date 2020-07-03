void leftadjust(TreeNode*& pleft)
{
	TreeNode* node = pleft;
	while (pleft->right != nullptr)
		pleft = pleft->right;

	if (node->left != nullptr)
	{
		leftadjust(node->left);
		node->left->right = node;
	}

	if (node->right != nullptr)
	{
		rightadjust(node->right);
		node->right->left = node;
	}
}
void rightadjust(TreeNode*& pright)
{
	TreeNode* node = pright;
	while (pright->left != nullptr)
		pright = pright->left;

	if (node->left != nullptr)
	{
		leftadjust(node->left);
		node->left->right = node;
	}

	if (node->right != nullptr)
	{
		rightadjust(node->right);
		node->right->left = node;
	}
}

TreeNode* Convert(TreeNode* pRootOfTree)
{
	rightadjust(pRootOfTree);
	return pRootOfTree;
}