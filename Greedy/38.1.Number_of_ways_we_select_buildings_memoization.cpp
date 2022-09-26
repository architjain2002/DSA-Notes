
// Intuition :

// Idea here is similar to that of Knapsack Problem.
// We have two choices for each building.
// Either pick it
// Or skip it
// Using this way, we can move across given string and get count. And when length of selected string exceeds 3, simply return from there.
// Just here we need to track previous element, so that we do not end up picking same type of buildings.

// Thus, we have total three state and dp will look like :

// idx : current index
// prev : previous chosen building
// len : length/number of buildings picked.
// Base condition is when we either have picked 3 buildings, or else we have reached end of string.
// Note : We are assuming that if no building is picked, then prev = 2

class Solution
{
private:
    long long dp[100003][3][4];

    long long solve(string &s, int idx, int prev, int len, int n)
    {
        if (len == 3)
            return 1;
        if (idx == n)
        {
            return 0;
        }
        if (dp[idx][prev][len] != -1)
            return dp[idx][prev][len];

        long long res = solve(s, idx + 1, prev, len, n);

        if (prev != (s[idx] - '0'))
        {
            res += solve(s, idx + 1, s[idx] - '0', len + 1, n);
        }
        return dp[idx][prev][len] = res;
    }

public:
    long long numberOfWays(string s)
    {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 2, 0, n);
    }
};