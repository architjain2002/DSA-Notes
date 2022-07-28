class Solution
{
public:
    int solve(int curr, vector<int> &nums, int dp[])
    {
        if (dp[curr] != -1)
        {
            return dp[curr];
        }
        if (curr > nums.size() - 1)
        {
            return 0;
        }
        return dp[curr] = max(nums[curr] + solve(curr + 2, nums, dp), solve(curr + 1, nums, dp));
    }

    int rob(vector<int> &nums)
    {
        int dp[10000];
        memset(dp, -1, sizeof(dp));
        return solve(0, nums, dp);
    }
};