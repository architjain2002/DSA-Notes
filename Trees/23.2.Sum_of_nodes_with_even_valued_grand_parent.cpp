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
    int sum = 0;
    void traversal(TreeNode *root, int parent, int grandparent)
    {
        if (root == nullptr)
            return;
        if (grandparent % 2 == 0)
            sum = sum + root->val;

        traversal(root->left, root->val, parent);
        traversal(root->right, root->val, parent);
    }
    int sumEvenGrandparent(TreeNode *root)
    {
        traversal(root, -1, -1);
        return sum;
    }
};