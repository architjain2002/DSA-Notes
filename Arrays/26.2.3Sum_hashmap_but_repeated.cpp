class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            unordered_map<int, int> mp;

            int target = 0 - nums[i];

            for (int j = i + 1; j < nums.size(); j++)
            {
                int val = target - nums[j];

                if (mp.find(val) != mp.end())
                {
                    ans.push_back({nums[i], val, nums[j]});
                }
                mp[nums[j]] = nums[j];
            }
        }

        return ans;
    }
};