#include <iostream>
#include <vector>

using namespace std;

void solve(int ind, vector<int> &nums, int count, int &max)
{
    if (ind >= nums.size() - 1)
    {
        if (count < max)
        {
            max = count;
        }
        return;
    }
    for (int i = ind + 1; i <= ind + nums[ind]; i++)
    {
        solve(i, nums, count + 1, max);
    }
    return;
}
int jump(vector<int> &nums)
{
    int max = nums.size() - 1; // maximum steps possible
    solve(0, nums, 0, max);
    return max;
}

int main(int argc, char const *argv[])
{
    // vector<int> nums = {5, 6, 4, 4, 6, 9, 4, 4, 7, 4, 4, 8, 2, 6, 8, 1, 5, 9, 6, 5, 2, 7, 9, 7, 9, 6, 9, 4, 1, 6, 8, 8, 4, 4, 2, 0, 3, 8, 5};
    vector<int> nums = {2, 0, 1, 1, 1, 2};
    cout << jump(nums) << endl;

    return 0;
}
