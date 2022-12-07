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
    void inorder(TreeNode *root, int &sum)
    {
        if (root == nullptr)
            return;
        if (root->val % 2 == 0)
        {
            int val = 0;
            grandparent(root, 0, val);
            sum = sum + val;
        }
        inorder(root->left, sum);
        inorder(root->right, sum);
    }

    void grandparent(TreeNode *root, int depth, int &sum)
    {
        if (root == nullptr)
            return;
        if (depth == 2)
        {
            sum = sum + root->val;
        }
        grandparent(root->left, depth + 1, sum);
        grandparent(root->right, depth + 1, sum);
    }
    int sumEvenGrandparent(TreeNode *root)
    {
        int sum = 0;
        inorder(root, sum);
        return sum;
    }
};