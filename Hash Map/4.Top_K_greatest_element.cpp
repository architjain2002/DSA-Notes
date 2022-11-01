class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<int> arr;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        int mx = 0;
        int ans = nums[0];
        for (int i = 0; i < k; i++)
        {
            mx = 0;
            for (auto x : mp)
            {
                if (x.second > mx)
                {
                    mx = x.second;
                    ans = x.first;
                }
            }
            arr.push_back(ans);
            mp.erase(ans);
        }

        return arr;
    }
};