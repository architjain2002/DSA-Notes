
class Solution
{
public:
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree

    int solve(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int curr = node->data;

        int l = solve(node->left);
        int r = solve(node->right);

        node->data = l + r;
        return curr + l + r;
    }
    void toSumTree(Node *node)
    {
        solve(node);
        return;
    }
};