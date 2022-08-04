//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(int *arr, int n)
    {
        int prevans2 = arr[0];
        int prevans = max(arr[0], arr[1]);
        int currans = prevans;

        if (n == 1)
        {
            return arr[0];
        }

        for (int i = 2; i < n; i++)
        {
            currans = max(prevans, prevans2 + arr[i]);
            prevans2 = prevans;
            prevans = currans;
        }

        return currans;
    }
};