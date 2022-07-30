class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {

        int dp[matrix.size() + 1][matrix[0].size() + 1];
        memset(dp, 0, sizeof(dp));

        int maxVal = INT_MIN;
        for (int i = 1; i <= matrix.size(); i++)
        {
            for (int j = 1; j <= matrix[0].size(); j++)
            {
                if (matrix[i - 1][j - 1] == '0')
                {
                    dp[i][j] = 0;
                }

                else
                {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
                maxVal = max(maxVal, dp[i][j]);
            }
        }

        return maxVal * maxVal;
    }
};