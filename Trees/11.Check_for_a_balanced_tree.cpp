class Solution
{
public:
    // Function to check whether a binary tree is balanced or not.

    int height(Node *node)
    {
        if (node == nullptr)
            return 0;
        int lh = 1 + height(node->left);
        int rh = 1 + height(node->right);

        return max(lh, rh);
    }
    bool isBalanced(Node *root)
    {
        if (root == nullptr)
            return true;

        int left = height(root->left);
        int right = height(root->right);

        return (abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right));
    }
};