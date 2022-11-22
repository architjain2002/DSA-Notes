class Solution
{
public:
    /*You are required to complete this method*/
    int solve(Node *root, bool &ans)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int r = solve(root->right, ans);
        int l = solve(root->left, ans);

        if (r != l && root->left != nullptr && root->right != nullptr)
        {
            ans = false;
        }
        return 1 + max(r, l);
    }
    bool check(Node *root)
    {
        bool ans = true;
        solve(root, ans);
        return ans;
    }
};