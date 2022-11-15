class Solution
{
public:
    // Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node *node)
    {
        if (node == nullptr)
            return {};
        queue<Node *> q;
        q.push(node);
        vector<int> ans;
        while (!q.empty())
        {
            node = q.front();
            q.pop();
            ans.push_back(node->data);
            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
        }
        return ans;
    }
};