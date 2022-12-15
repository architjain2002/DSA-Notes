/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int maxAncestorDiff(TreeNode *root)
    {
        return solve(root, root->val, root->val);
    }

    int solve(TreeNode *root, int cur_max, int cur_min)
    {
        if (root == nullptr)
        {
            return cur_max - cur_min;
        }

        cur_max = max(root->val, cur_max);
        cur_min = min(root->val, cur_min);
        int l = solve(root->left, cur_max, cur_min);
        int r = solve(root->right, cur_max, cur_min);
        return max(l, r);
    }
};