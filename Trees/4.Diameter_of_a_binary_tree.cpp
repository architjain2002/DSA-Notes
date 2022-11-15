class Solution
{
public:
    // Function to return the diameter of a Binary Tree.
    int res = 0;
    int height(Node *root)
    {
        if (root == NULL)
            return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        int height = 1 + max(lh, rh);
        res = max(res, 1 + lh + rh);
        return height;
    }

    int diameter(Node *root)
    {

        height(root);
        return res;
    }
};