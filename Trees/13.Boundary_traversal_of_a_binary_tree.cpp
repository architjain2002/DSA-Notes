class Solution
{
public:
    bool is_leaf(Node *root)
    {
        if (root->left == NULL && root->right == NULL)
            return true;
        return false;
    }
    void left_boundary(Node *root, vector<int> &v)
    {
        Node *cur = root->left;
        while (cur)
        {
            if (!is_leaf(cur))
                v.push_back(cur->data);
            if (cur->left)
                cur = cur->left;
            else
                cur = cur->right;
        }
    }
    void leaf_boundary(Node *root, vector<int> &v)
    {
        if (is_leaf(root))
        {
            v.push_back(root->data);
            return;
        }
        if (root->left)
            leaf_boundary(root->left, v);
        if (root->right)
            leaf_boundary(root->right, v);
    }
    void right_boundary(Node *root, vector<int> &v)
    {
        Node *cur = root->right;
        stack<int> st;
        while (cur)
        {
            if (!is_leaf(cur))
                st.push(cur->data);
            if (cur->right)
                cur = cur->right;
            else
                cur = cur->left;
        }
        while (!st.empty())
        {
            v.push_back(st.top());
            st.pop();
        }
    }
    vector<int> boundary(Node *root)
    {
        vector<int> res;
        if (root == NULL)
            return res;
        res.push_back(root->data);
        left_boundary(root, res);
        if (!is_leaf(root))
            leaf_boundary(root, res);
        right_boundary(root, res);
        return res;
    }
};