void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    if ((n == 0) || (k <= 0))
        return;
    int curr = 0, start = 0, tmp = 0;
    int numToBeRotated = nums[0];
    for (int i = 0; i < n; i++)
    {
        tmp = nums[(curr + k) % n];
        nums[(curr + k) % n] = numToBeRotated;
        numToBeRotated = tmp;
        curr = (curr + k) % n;
        if (curr == start)
        {
            numToBeRotated = nums[++curr];
            ++start;
        }
    }
}