// Function to return a list containing elements of left view of the binary tree.

vector<int> leftView(Node *root)
{
    vector<int> ans;
    if (root == nullptr)
        return ans;
    queue<Node *> q;
    q.push(root);
    ans.push_back(root->data);
    q.push(nullptr);
    while (q.size() > 1)
    {
        Node *curr = q.front();
        q.pop();
        if (curr == nullptr)
        {
            ans.push_back(q.front()->data);
            q.push(nullptr);
            continue;
        }
        if (curr->left != nullptr)
        {
            q.push(curr->left);
        }
        if (curr->right != nullptr)
        {
            q.push(curr->right);
        }
    }
    return ans;
}