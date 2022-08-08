// here although optimized than the recursive yet we are using N*N*K space
// hence we need to optimize our idea further
class Solution
{
public:
    int solve(int i, int j, int k, vector<int> &A, int n, int dp[400][400][100])
    {
        if (j >= n || i >= n || k <= 0)
        {
            return dp[i][j][k] = 0;
        }
        if (dp[i][j][k] != -1)
        {
            return dp[i][j][k];
        }

        if (k != 0)
        {
            return dp[i][j][k] = max({
                       solve(j + 1, j + 2, k - 1, A, n, dp) + (A[j] - A[i]),
                       solve(i, j + 1, k, A, n, dp),
                       solve(i + 1, j + 1, k, A, n, dp),
                   });
        }
        return dp[i][j][k];
    }
    int maxProfit(int k, vector<int> &prices)
    {
        int dp[400][400][100];
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, k, prices, prices.size(), dp);
    }
};