class Solution
{
public:
    int solve(vector<int> &satisfaction, int i, int k, int mem[1000][1000])
    {
        if (i == satisfaction.size())
            return 0;
        if (k > satisfaction.size())
            return 0;
        if (mem[i][k] != -1)
            return mem[i][k];

        return mem[i][k] = max(
                   solve(satisfaction, i + 1, k + 1, mem) + satisfaction[i] * k,
                   solve(satisfaction, i + 1, k, mem));
    }

    int
    maxSatisfaction(vector<int> &satisfaction)
    {
        // n dishes -- any dish in 1 time
        //  to return max(time[i]* sat[i])
        int mem[1000][1000];
        memset(mem, -1, sizeof(mem));
        sort(satisfaction.begin(), satisfaction.end());
        return solve(satisfaction, 0, 1, mem);
    }
};
