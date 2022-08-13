
class Solution
{
public:
    int findPlatform(int arr[], int dep[], int n)
    {
        vector<int> dp(2400, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i]; j <= dep[i]; j++)
            {
                dp[j]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < 2400; i++)
        {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
}