class Solution
{
public:
	vector<int> postorderTraversal(TreeNode* root)
	{
		vector<int> rv;
		if (root == nullptr)
			return rv;
		stack<TreeNode*> st;
		stack<int> flag;

		st.push(root);
		flag.push('L');

		while (!st.empty())
		{
			if (flag.top() == 'L')
			{
				flag.pop();
				flag.push('R');

				if (st.top()->left != nullptr)
				{
					st.push(st.top()->left);
					flag.push('L');
				}
			}
			else if (flag.top() == 'R')
			{
				flag.pop();
				flag.push('F');

				if (st.top()->right != nullptr)
				{
					st.push(st.top()->right);
					flag.push('L');
				}
			}
			else
			{
				rv.push_back(st.top()->val);
				st.pop();
				flag.pop();
			}
		}
		return rv;
	}
};