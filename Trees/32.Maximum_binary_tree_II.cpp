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
    void solve(TreeNode *root, int val)
    {
        if (root->right == nullptr)
        {
            root->right = new TreeNode(val);
            return;
        }

        if (root->right && root->right->val < val)
        {
            TreeNode *node = new TreeNode(val);

            TreeNode *temp = root->right;
            root->right = node;
            node->left = temp;
        }
        else
        {
            solve(root->right, val);
        }
        return;
    }
    TreeNode *insertIntoMaxTree(TreeNode *root, int val)
    {
        if (root->val < val)
        {
            TreeNode *node = new TreeNode(val);
            node->left = root;
            return node;
        }
        solve(root, val);
        return root;
    }
};