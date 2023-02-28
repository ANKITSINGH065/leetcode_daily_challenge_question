class Solution
{
public:
    string solve(TreeNode *root, vector<TreeNode *> &res, unordered_map<string, int> &mp)
    {

        if (root == NULL)
        {
            return "NULL";
        }

        string str = to_string(root->val) + "," + solve(root->left, res, mp) + "," + solve(root->right, res, mp);

        if (mp[str] == 1)
        {
            res.push_back(root);
        }

        mp[str]++;

        return str;
    }
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {

        unordered_map<string, int> mp;
        vector<TreeNode *> res;

        solve(root, res, mp);

        return res;
    }
};