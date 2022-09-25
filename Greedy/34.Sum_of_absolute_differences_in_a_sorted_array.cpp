
// res[i] = (nums[i] - nums[0]) + (nums[i] - nums[1]) + ... + (nums[i] - nums[i - 1])        <--- absolute difference of nums[i] with first i numbers
//      + (nums[i] - nums[i]) + (nums[i + 1] - nums[i]) + (nums[i + 2] - nums[i]) + ... + (nums[n - 1] - nums[i])   <--- absolute difference of nums[i] with last n - i numbers

// after simplification:
//  res[i] = i * nums[i] - (nums[0] + ... + nums[i - 1])        <--- absolute difference of nums[i] with first i numbers
//       + (nums[i + 1] + ... + nums[n]) - (n - i) * nums[i]   <--- absolute difference of nums[i] with last n - i numbers

// finally we get this eq through which we find our answer in O(n) time
// res[i] = i * nums[i] - prefixSum[i] + (prefixSum[n] - prefixSum[i] - (n - i) * nums[i])

class Solution
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n);
        vector<int> prefixSum(n + 1);
        for (int i = 0; i < n; ++i)
        {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        for (int i = 0; i < n; ++i)
        {
            res[i] = i * nums[i] - prefixSum[i] + (prefixSum[n] - prefixSum[i] - (n - i) * nums[i]);
        }
        return res;
    }
};