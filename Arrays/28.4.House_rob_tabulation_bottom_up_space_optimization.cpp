
// We can optimize the space now,
// as we can see we only need to know the answer till (i-1)th idx and (i-2)th idx to have an answer for the (i)th idx.
//  And we don't really care about the whole dp-vector, so there is no point maintaining one... 3 variables will do the job, prev_ans (for i-1), prev_ans2(for i-2) and curr_ans !!

// dp[i - 2] - previous answer(till i-2 idx) -> prev_ans2
// dp[i - 1] - previous answer(till i-1 idx) -> prev_ans
// dp[i] - current answer(can be prev_ans or prev_ans2+nums[i]) -> curr_ans
// So we will get rid of the dp-vector and thus our SC will get reduced down to O(1)
// (It is very similar to fibonacci series Space optimization)

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        int prev_ans2 = nums[0], prev_ans = max(nums[0], nums[1]), curr_ans = prev_ans;

        for (int i = 2; i < n; i++)
        {
            curr_ans = max(prev_ans, prev_ans2 + nums[i]);
            prev_ans2 = prev_ans;
            prev_ans = curr_ans;
        }
        return curr_ans;
    }
};