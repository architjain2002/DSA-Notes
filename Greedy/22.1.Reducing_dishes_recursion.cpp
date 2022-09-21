class Solution
{
public:
    int solve(vector<int> &satisfaction, int i, int k)
    {
        if (i == satisfaction.size())
            return 0;
        if (k > satisfaction.size())
            return 0;

        return max(
            solve(satisfaction, i + 1, k + 1) + satisfaction[i] * k,
            solve(satisfaction, i + 1, k));
    }

    int maxSatisfaction(vector<int> &satisfaction)
    {
        // n dishes -- any dish in 1 time
        //  to return max(time[i]* sat[i])

        sort(satisfaction.begin(), satisfaction.end());
        return solve(satisfaction, 0, 1);
    }
};