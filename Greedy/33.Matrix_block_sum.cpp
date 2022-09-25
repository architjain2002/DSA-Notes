

// This question is similar to a vector segment sum.

// To extract sum of an arbitrary sub-array, we first form a prefix sum array.
// [1, 2, 3, 4, 5] // original vector
// [1, 3, 6, 10, 15] // prefix sum

// To get sum of a sub array from index a to index b, sum(a, b), we can instead calculate prefix(b) - prefix(a-1)

// Similar in 2D, we form prefix matrix, where sum[i][j] = sum of elements on top left of original matrix
// [1, 2, 3]
// [4, 5, 6]
// [7, 8, 9]

// [1, 3, 6]
// [5, 12, 21]
// [12, 27, 45]

// Similarly, Sum of an arbitrary block from (i-K, j-K) to (i+K, j+K)
// ans(i, j) = prefix(i+K, j+K) - prefix(i+K, j-K-1) - prefix (i-K-1, j+K) + prefix(i-K-1, j-K-1);

class Solution
{
public:
    int sizeX, sizeY;
    int extractSum(int i, int j, const vector<vector<int>> &sum)
    {
        if (i < 0 || j < 0)
            return 0;
        if (i >= sizeX)
            i = sizeX - 1;
        if (j >= sizeY)
            j = sizeY - 1;
        return sum[i][j];
    }

    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int K)
    {
        sizeX = mat.size();
        sizeY = mat[0].size();

        vector<vector<int>> sum(sizeX, vector<int>(sizeY, 0));
        // Calculate prefix matrix
        for (int i = 0; i < sizeX; i++)
        {
            for (int j = 0; j < sizeY; j++)
            {
                sum[i][j] = mat[i][j] + extractSum(i - 1, j, sum) + extractSum(i, j - 1, sum) - extractSum(i - 1, j - 1, sum);
            }
        }

        // Use prefix matrix to calculate our sum
        vector<vector<int>> ans(sizeX, vector<int>(sizeY, 0));
        for (int i = 0; i < sizeX; i++)
        {
            for (int j = 0; j < sizeY; j++)
            {
                ans[i][j] = extractSum(i + K, j + K, sum) - extractSum(i + K, j - K - 1, sum) - extractSum(i - K - 1, j + K, sum) + extractSum(i - K - 1, j - K - 1, sum);
            }
        }

        return ans;
    }
};