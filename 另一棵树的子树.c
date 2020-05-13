bool TreeEqual(struct TreeNode* ptn1, struct TreeNode* ptn2)
{
	if (ptn1 == NULL && ptn2 == NULL)
		return true;
	if (ptn1 == NULL || ptn2 == NULL)
		return false;
	return ptn1->val == ptn2->val && TreeEqual(ptn1->left, ptn2->left) && TreeEqual(ptn1->right, ptn2->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t)
{
	if (t == NULL)
		return true;
	if (s == NULL)
		return false;
	if (TreeEqual(s, t))
		return true;
	return  isSubtree(s->left, t) || isSubtree(s->right, t);
}