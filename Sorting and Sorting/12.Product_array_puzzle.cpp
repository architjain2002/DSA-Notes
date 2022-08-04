//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int> &arr, int n)
    {
        vector<long long int> ans(n, 0);
        int count = 0;
        int ind = 0;
        long long prod = 1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                count++;
                ind = i;
            }
            if (arr[i] != 0)
            {
                prod = prod * arr[i];
            }
        }
        if (count == 0)
        {
            for (int i = 0; i < n; i++)
            {
                ans[i] = prod / arr[i];
            }
        }
        else if (count == 1)
        {
            ans[ind] = prod;
        }

        return ans;
    }
};