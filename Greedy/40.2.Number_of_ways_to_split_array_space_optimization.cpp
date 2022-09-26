class Solution
{
public:
    int waysToSplitArray(vector<int> &nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        long long prefix = nums[0];

        long long suffix = 0;

        for (int i = nums.size() - 1; i >= 1; i--)
        {
            suffix = suffix + nums[i];
        }

        int count = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (prefix >= suffix)
            {
                count++;
            }
            prefix = prefix + nums[i + 1];
            suffix = suffix - nums[i + 1];
        }
        return count;
    }
};