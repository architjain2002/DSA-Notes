class Solution
{
public:
    int solve(int i, int j, vector<vector<char>> &matrix, int dp[302][302])
    {
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (i < matrix.size() && j < matrix[0].size())
        {
            if (matrix[i][j] == '1')
            {
                return dp[i][j] = min({solve(i + 1, j, matrix, dp), solve(i, j + 1, matrix, dp), solve(i + 1, j + 1, matrix, dp)}) + 1;
            }
        }
        return dp[i][j] = 0;
    }

    int maximalSquare(vector<vector<char>> &matrix)
    {

        int dp[302][302];
        memset(dp, -1, sizeof(dp));
        int maxVal = INT_MIN;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                int val = solve(i, j, matrix, dp);
                maxVal = max(val, maxVal);
            }
        }

        return maxVal * maxVal;
    }
};