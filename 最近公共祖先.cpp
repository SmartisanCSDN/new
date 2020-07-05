class Solution
{
public:
	bool isancestor(TreeNode* ancestor, TreeNode* child)
	{
		if (ancestor == nullptr)
			return false;
		else if (ancestor == child)
			return true;
		else
			return isancestor(ancestor->left, child) || isancestor(ancestor->right, child);
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		stack<TreeNode*> way;
		way.push(root);
		while (way.top() != p)
		{
			if (isancestor(way.top()->left, p))
				way.push(way.top()->left);
			else
				way.push(way.top()->right);
		}
		while (!way.empty())
		{
			if (isancestor(way.top(), q))
				break;
			way.pop();
		}
		return way.top();
	}
};