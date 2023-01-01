// Function to find the minimum element in the given BST.
void solve(Node *root, int &ans)
{
    if (!root)
        return;

    ans = min(ans, root->data);

    if (root->left)
    {
        solve(root->left, ans);
        return;
    }
    if (root->right)
    {
        solve(root->left, ans);
        return;
    }
}

int minValue(Node *root)
{
    if (!root)
        return -1;
    int ans = root->data;
    solve(root, ans);
    return ans;
}