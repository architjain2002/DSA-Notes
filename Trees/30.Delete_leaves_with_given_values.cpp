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
    bool check(TreeNode *root)
    {
        if (root->left == nullptr && root->right == nullptr)
            return true;
        else
            return false;
    }

    void solve(TreeNode *root, int target)
    {
        if (root == nullptr)
            return;

        solve(root->left, target);
        solve(root->right, target);

        if (root->left && root->left->val == target && check(root->left))
        {
            delete root->left;
            root->left = nullptr;
        }
        if (root->right && root->right->val == target && check(root->right))
        {
            delete root->right;
            root->right = nullptr;
        }
    }
    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        solve(root, target);
        if (check(root) && root->val == target)
            return nullptr;
        return root;
    }
};