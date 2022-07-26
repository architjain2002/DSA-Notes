class Solution
{
public:
    // bool dp[10000];
    // memset(dp,false,sizeof(dp));
    bool solve(int ind, vector<int> &nums)
    {
        bool dp[10003];
        memset(dp, false, sizeof(dp));
        dp[nums.size() - 1] = true;

        for (int i = ind - 1; i >= 0; i--)
        {
            for (int j = i + 1; j <= nums[i] + i; j++)
                if (j <= nums.size() - 1 && dp[j] == true)
                {
                    dp[i] = true;
                    break;
                }
        }
        return dp[0];
    }

    bool canJump(vector<int> &nums)
    {
        int ind = nums.size() - 1;
        return solve(ind, nums);
    }
};