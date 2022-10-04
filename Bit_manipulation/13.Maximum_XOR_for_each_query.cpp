class Solution
{
public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
    {
        vector<int> prefix_XOR(nums.size());
        prefix_XOR[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            prefix_XOR[i] = prefix_XOR[i - 1] ^ nums[i];
        }
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            ans[i] = prefix_XOR[nums.size() - i - 1] ^ (int)(pow(2, maximumBit) - 1);
        }
        return ans;
    }
};