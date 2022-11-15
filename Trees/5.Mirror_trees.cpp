class Solution
{
public:
    // Function to convert a binary tree into its mirror tree.

    void solve(Node *node)
    {
        if (node == nullptr)
            return;

        solve(node->left);
        solve(node->right);

        Node *temp = node->left;
        node->left = node->right;
        node->right = temp;
    }

    void mirror(Node *node)
    {
        solve(node);
        return;
    }
};