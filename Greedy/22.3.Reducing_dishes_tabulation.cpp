class Solution
{
public:
    int solve(vector<int> &satisfaction)
    {
        int mem[1000][1000];
        memset(mem, 0, sizeof(mem));
        for (int i = satisfaction.size() - 1; i >= 0; i--)
        {
            for (int k = satisfaction.size(); k >= 1; k--)
            {
                mem[i][k] = max(k * satisfaction[i] + mem[i + 1][k + 1],
                                mem[i + 1][k]);
            }
        }
        return mem[0][1];
    }

    int maxSatisfaction(vector<int> &satisfaction)
    {
        // n dishes -- any dish in 1 time
        //  to return max(time[i]* sat[i])
        sort(satisfaction.begin(), satisfaction.end());
        return solve(satisfaction);
    }
};