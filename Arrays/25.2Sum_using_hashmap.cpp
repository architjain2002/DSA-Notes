class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int val;
        unordered_map<int, int> mp; // O(n) space and O(nlogn) time
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            val = target - nums[i];
            if (mp.find(val) != mp.end())
            {
                ans.push_back(mp[val]);
                ans.push_back(i);
            }
            mp[nums[i]] = i;
        }

        return ans;
    }
};