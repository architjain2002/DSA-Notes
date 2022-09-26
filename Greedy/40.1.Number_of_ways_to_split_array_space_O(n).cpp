class Solution
{
public:
    int waysToSplitArray(vector<int> &nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<long long> prefix(nums.size(), 0);
        vector<long long> suffix(nums.size(), 0);

        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        suffix[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            suffix[i] = suffix[i + 1] + nums[i];
        }

        int count = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (prefix[i] >= suffix[i + 1])
            {
                count++;
            }
        }
        return count;
    }
};