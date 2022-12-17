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
    TreeNode *solve(int start, int end, vector<int> &nums)
    {
        if (start > end)
        {
            return nullptr;
        }
        int mx = 0;
        int ind = start;
        for (int i = start; i <= end; i++)
        {
            if (mx < nums[i])
            {
                mx = nums[i];
                ind = i;
            }
        }
        TreeNode *root = new TreeNode(mx);
        root->left = solve(start, ind - 1, nums);
        root->right = solve(ind + 1, end, nums);
        return root;
    }
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return solve(0, nums.size() - 1, nums);
    }
};