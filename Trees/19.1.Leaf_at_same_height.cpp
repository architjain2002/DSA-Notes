class Solution
{

public:
    /*You are required to complete this method*/

    int height(struct Node *root)
    {

        // code here

        if (root == NULL)
            return 0;

        int l = height(root->left);

        int r = height(root->right);

        return 1 + max(l, r);
    }

    bool check(Node *root)

    {

        bool ans = true;

        if (root == NULL)
            return ans;

        if (root->right == NULL)
            return check(root->left);

        if (root->left == NULL)
            return check(root->right);

        if (height(root->right) != height(root->left))
            return false;

        if (!check(root->right) || !check(root->left))
            return false;

        return true;
    }
};