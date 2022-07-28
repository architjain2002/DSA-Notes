class Solution
{
public:
    int solve(int curr, vector<int> &nums)
    {

        if (curr > nums.size() - 1)
        {
            return 0;
        }
        return max(nums[curr] + solve(curr + 2, nums), solve(curr + 1, nums));
    }

    int rob(vector<int> &nums)
    {
        return solve(0, nums);
    }
};