//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int smallestSubWithSum(int arr[], int n, int x)
    {
        int small = 0;
        int start = 0;
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            small = small + arr[i];
            if (small > x)
            {
                while (start <= i && small > x)
                {
                    small = small - arr[start];
                    ans = min(ans, i - start + 1);
                    start++;
                }
            }
        }
        return ans;
    }
};