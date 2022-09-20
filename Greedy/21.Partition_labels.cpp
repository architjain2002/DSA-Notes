class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        unordered_map<char, int> mp;

        for (int i = 0; i < s.length(); i++)
        {
            mp[s[i]] = i;
        }

        int maxi = 0;
        int prev = -1;
        vector<int> res;
        for (int i = 0; i < s.length(); i++)
        {
            maxi = max(maxi, mp[s[i]]);
            if (maxi == i)
            {
                res.push_back(maxi - prev);
                prev = maxi;
            }
        }

        return res;
    }
};