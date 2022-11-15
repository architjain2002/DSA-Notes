// Should return  right view of tree
class Solution
{
public:
    // Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
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

            if (curr->right != nullptr)
                q.push(curr->right);
            if (curr->left != nullptr)
                q.push(curr->left);
        }
        return ans;
    }
};