
class Solution
{

    void creatMapping(vector<int> in, int n, map<int, int> &m)
    {

        for (int i = 0; i < n; i++)
        {

            m[in[i]] = i;
        }
    }

    TreeNode *solve(vector<int> in, vector<int> post, int &index, int start, int end, int n, map<int, int> &m)
    {

        if (index >= n || start > end)
        {
            return NULL;
        }

        int element = post[index--];
        TreeNode *root = new TreeNode(element);
        int pos = m[element];

        root->right = solve(in, post, index, pos + 1, end, n, m);

        root->left = solve(in, post, index, start, pos - 1, n, m);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {

        map<int, int> m;

        int n = inorder.size();
        F

            creatMapping(inorder, n, m);
        int postindex = n - 1;

        TreeNode *ans = solve(inorder, postorder, postindex, 0, n - 1, n, m);

        return ans;
    }
};