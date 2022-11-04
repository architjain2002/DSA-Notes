class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        ios_base ::sync_with_stdio(false);
        cin.tie(nullptr);

        int slow = 0;
        int fast = 0;
        slow = nums[slow];
        fast = nums[nums[fast]];

        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        int enter = 0;
        while (enter != slow)
        {
            slow = nums[slow];
            enter = nums[enter];
        }

        return slow;
    }
};