int mab(int a, int b)
{
	return a > b ? a - b : b - a;
}

int maxDepth(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	else
	{
		int left = maxDepth(root->left);
		int right = maxDepth(root->right);
		return (left > right ? left : right) + 1;
	}
}




bool isBalanced(struct TreeNode* root)
{
	if (root == NULL)
		return true;
	int left = maxDepth(root->left);
	int right = maxDepth(root->right);
	return mab(left, right) < 2 && isBalanced(root->left) && isBalanced(root->right);

}
