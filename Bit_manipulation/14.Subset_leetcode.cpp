class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        unsigned int pow_set_size = pow(2, nums.size());
        vector<vector<int>> vec(pow_set_size);

        for (int i = 0; i < pow_set_size; i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (i & (1 << j))
                {
                    vec[i].push_back(nums[j]);
                }
            }
        }
        return vec;
    }
};