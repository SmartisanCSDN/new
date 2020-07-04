class Solution
{
public:
	vector<int> preorderTraversal(TreeNode* root)
	{
		vector<int> rv;
		stack<TreeNode*> st;

		if (root == nullptr)
			return rv;
		st.push(root);

		while (!st.empty())
		{
			TreeNode* node = st.top();
			rv.push_back(node->val);
			st.pop();
			if (node->right != nullptr)
				st.push(node->right);
			if (node->left != nullptr)
				st.push(node->left);
		}
		return rv;
	}
};