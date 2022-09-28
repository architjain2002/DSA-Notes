//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums)
    {
        int set_bit;
        int XOR = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            XOR = XOR ^ nums[i];
        }
        set_bit = XOR & ~(XOR - 1);
        int a = 0;
        int b = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (set_bit & nums[i])
            {
                a = a ^ nums[i];
            }

            else
            {
                b = b ^ nums[i];
            }
        }
        if (a > b)
        {
            return {b, a};
        }
        else
        {
            return {a, b};
        }
    }
};