class Solution
{
public:
    string tree2str(TreeNode* t)
    {
        string str;
        if(t == nullptr)
        return str;
        bt(str, t);
        return str;
                                                    
    }
protected:
    void bt(string& str, TreeNode* t)
    {
        str += to_string(t->val);
        if(t->left == nullptr && t->right == nullptr)
            return;
        else
        {
            if(t->left != nullptr)
            {
                str += '(';
                bt(str, t->left);
                str += ')';
            }
            if(t->right != nullptr)
            {
                if(t->left == nullptr)
                {
                    str += "()";
                }
                str += '(';
                bt(str, t->right);
                str += ')';
            
            }
        }
    }
};
