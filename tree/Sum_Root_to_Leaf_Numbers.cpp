

// using backtraking
class Solution
{
public:
    void solve(TreeNode *root, int num, int &sum)
    {
        if (!root)
            return; // Base condition for pre-order traversal, if root is NULL then we simply return.
        // below steps should be done before entring the child.
        num = num * 10 + root->val; // storing value of each node in the path in num.
        if (!root->left && !root->right)
            sum += num;              // we only add num to sum if currrent node is leaf node.
        solve(root->left, num, sum); // recursively calling for child nodes.
        solve(root->right, num, sum);
        num = num / 10; // backtracking in order to generate num for new paths while leaving the child node.
    }
    int sumNumbers(TreeNode *root)
    {
        int sum = 0;         // to store final answer
        solve(root, 0, sum); // calling the pre-order traversal function.
        return sum;          // returning our answer.
    }
};
// using BFS
class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        queue<pair<TreeNode *, int>> bfs;
        bfs.push({root, root->val});

        pair<TreeNode *, int> curr;
        int total_sum = 0;

        while (!bfs.empty())
        {
            curr = bfs.front();
            bfs.pop();

            if (!curr.first->left && !curr.first->right)
                total_sum += curr.second;

            if (curr.first->left)
                bfs.push({curr.first->left, (curr.second * 10 + curr.first->left->val)});
            if (curr.first->right)
                bfs.push({curr.first->right, (curr.second * 10 + curr.first->right->val)});
        }

        return total_sum;
    }
};

// using DFS
class Solution
{
public:
    int dfs(TreeNode *root, int curr)
    {

        if (root == NULL)
        {

            return 0;
        }

        curr = curr * 10 + root->val;

        if (root->left == NULL && root->right == NULL)
        {

            return curr;
        }

        return dfs(root->left, curr) + dfs(root->right, curr);
    }
    int sumNumbers(TreeNode *root)
    {

        return dfs(root, 0);
    }
};