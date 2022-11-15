class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        if (root == NULL)
            return {};
        queue<pair<Node *, int>> q;
        map<int, int> m;
        q.push({root, 0});

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            int x = cur.second;
            Node *temp = cur.first;

            if (m.find(x) == m.end())
                m[x] = temp->data;

            if (temp->left)
                q.push({temp->left, x - 1});
            if (temp->right)
                q.push({temp->right, x + 1});
        }
        vector<int> ans;
        for (auto x : m)
            ans.push_back(x.second);
        return ans;
    }
};