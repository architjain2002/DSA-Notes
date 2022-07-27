class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        set<vector<int>> ans;
        vector<vector<int>> finalans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            unordered_map<int, int> mp;
            if (i == 0 || nums[i] != nums[i - 1])
            {

                int target = 0 - nums[i];

                for (int j = i + 1; j < nums.size(); j++)
                {
                    int val = target - nums[j];
                    if (mp.find(val) != mp.end())
                    {
                        ans.insert({nums[i], val, nums[j]});
                    }
                    mp[nums[j]] = nums[j];
                }
            }
        }
        for (auto ele : ans)
        {
            finalans.push_back(ele);
        }

        return finalans;
    }
};