//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool solve(int i, int sum, int target, vector<long long> arr, int n)
    {
        if (sum == target)
        {
            return true;
        }

        if (i != n)
        {
            return (solve(i + 1, sum + arr[i], target, arr, n) || solve(i + 1, sum, target, arr, n));
        }

        return false;
    }

    long long smallestpositive(vector<long long> array, int n)
    {
        long long maxSum = 0;
        for (int i = 0; i < n; i++)
        {
            maxSum = maxSum + array[i];
        }

        for (int i = 1; i < maxSum; i++)
        {
            if (solve(0, 0, i, array, n) == false)
            {
                return i;
            }
        }

        return maxSum + 1;
    }
};