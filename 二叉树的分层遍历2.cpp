class Solution
{
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root)
	{
		vector<vector<int>> v_val;
		if (root == nullptr)
			return v_val;

		queue<TreeNode*> q_node;
		q_node.push(root);


		v_val.push_back(vector<int>(1, root->val));

		for (int i = 1;; ++i)
		{
			vector<int> val;
			int size = q_node.size();
			while (size--)
			{
				if (q_node.front()->left != nullptr)
				{
					q_node.push(q_node.front()->left);
					val.push_back(q_node.front()->left->val);
				}
				if (q_node.front()->right != nullptr)
				{
					q_node.push(q_node.front()->right);
					val.push_back(q_node.front()->right->val);
				}
				q_node.pop();
			}
			if (q_node.empty())
				break;
			v_val.push_back(vector<int>(val.begin(), val.end()));
		}
		int start = 0, end = v_val.size() - 1;
		while (start < end)
		{
			v_val[start].swap(v_val[end]);
			++start;
			--end;
		}
		return v_val;
	}
};