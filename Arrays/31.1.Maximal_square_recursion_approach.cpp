class Solution
{
public:
    int solve(int i, int j, vector<vector<char>> &matrix)
    {

        if (i < matrix.size() && j < matrix[0].size())
        {
            if (matrix[i][j] == '1')
            {
                return min({solve(i + 1, j, matrix), solve(i, j + 1, matrix), solve(i + 1, j + 1, matrix)}) + 1;
            }
        }
        return 0;
    }

    int maximalSquare(vector<vector<char>> &matrix)
    {

        int maxVal = INT_MIN;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                int val = solve(i, j, matrix);
                maxVal = max(val, maxVal);
            }
        }

        return maxVal * maxVal;
    }
};