class Solution
{
public:
    // bool dp[10000];
    // memset(dp,false,sizeof(dp));
    bool solve(int ind, vector<int> &nums, bool dp[])
    {

        if (ind == nums.size() - 1)
        {
            return dp[ind] = true;
        }

        if (dp[ind] == true)
        {
            return true;
        }

        for (int i = ind + 1; i <= ind + nums[ind]; i++)
        {
            if (solve(i, nums, dp))
            {
                return dp[ind] = true;
            }
        }
        return dp[ind] = false;
    }

    bool canJump(vector<int> &nums)
    {
        bool dp[10000];
        memset(dp, false, sizeof(dp));
        int ind = 0;
        return solve(ind, nums, dp);
    }
};