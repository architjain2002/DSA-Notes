class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        if (root == nullptr)
            return {};
        map<int, int> mp;
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            auto temp = q.front();
            q.pop();

            mp[temp.second] = temp.first->data;

            if (temp.first->left != nullptr)
                q.push({temp.first->left, temp.second - 1});
            if (temp.first->right != nullptr)
                q.push({temp.first->right, temp.second + 1});
        }
        vector<int> ans;
        for (auto x : mp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};