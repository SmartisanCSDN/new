class Solution
{
public:
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> rv;
		if (root == nullptr)
			return rv;
		stack<TreeNode*> st;
		stack<char> flag;

		st.push(root);
		flag.push('L');

		while (!st.empty())
		{
			if (flag.top() == 'L')
			{
				flag.pop();
				flag.push('R');

				TreeNode* node = st.top();
				if (node->left != nullptr)
				{
					st.push(st.top()->left);
					flag.push('L');
				}
			}
			else
			{
				TreeNode* node = st.top();
				rv.push_back(node->val);

				st.pop();
				flag.pop();

				if (node->right != nullptr)
				{
					st.push(node->right);
					flag.push('L');
				}
			}
		}
		return rv;
	}
};