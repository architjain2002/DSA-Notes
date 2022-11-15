vector<int> reverseLevelOrder(Node *node)
{
    if (node == nullptr)
        return {};
    queue<Node *> q;
    stack<Node *> st;
    q.push(node);
    vector<int> ans;
    while (!q.empty())
    {
        node = q.front();
        q.pop();
        st.push(node);
        if (node->right != nullptr)
            q.push(node->right);
        if (node->left != nullptr)
            q.push(node->left);
    }
    while (!st.empty())
    {
        ans.push_back(st.top()->data);
        st.pop();
    }
    return ans;
}