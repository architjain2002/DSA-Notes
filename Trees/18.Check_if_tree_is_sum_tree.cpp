// Should return true if tree is Sum Tree, else false
class Solution
{
public:
    int sum(Node *root, bool &ans)
    {

        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
        {
            return root->data;
        }

        int l = sum(root->left, ans);
        int r = sum(root->right, ans);
        if (l + r != root->data)
            ans = false;
        return l + r + root->data;
    }

    bool isSumTree(Node *root)
    {
        bool ans = true;
        sum(root, ans);
        return ans;
    }
};