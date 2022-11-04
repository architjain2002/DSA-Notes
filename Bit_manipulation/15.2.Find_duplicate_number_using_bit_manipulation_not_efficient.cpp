
// here we exceed the bit limitation of an integer of 32 bit,
// even if we use unsigned long long still for higher numbers it will not work
// but it is a good approach to understand some techniques
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {

        ios_base ::sync_with_stdio(false);
        cin.tie(nullptr);

        int temp = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if ((1 << nums[i]) & temp)
                return nums[i];
            temp = ((1 << nums[i]) | temp);
        }
        return -1;
    }
};