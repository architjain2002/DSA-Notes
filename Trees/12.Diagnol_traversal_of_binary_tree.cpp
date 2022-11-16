vector<int> diagonal(Node *root)
{
    if (root == nullptr)
        return {};
    deque<Node *> deq;
    deq.push_front(root);
    vector<int> ans;

    while (!deq.empty())
    {
        Node *temp = deq.front();
        deq.pop_front();
        ans.push_back(temp->data);

        if (temp->right != nullptr)
        {
            deq.push_front(temp->right);
        }
        if (temp->left != nullptr)
        {
            deq.push_back(temp->left);
        }
    }
    return ans;
}