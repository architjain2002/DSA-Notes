class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        return solve(0, 1, k, prices, prices.size());
    }
    int solve(int i, int j, int k, vector<int> &A, int n)
    {
        if (j >= n || i >= n || k == 0)
        {
            return 0;
        }

        if (k != 0)
        {
            return max({solve(j + 1, j + 2, k - 1, A, n) + (A[j] - A[i]),
                        solve(i, j + 1, k, A, n),
                        solve(i + 1, j + 1, k, A, n)});
        }
        return 0;
    }
};