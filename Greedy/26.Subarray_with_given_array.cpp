//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        int l = 0;
        int r = 0;
        long long sum = arr[l];
        while (l < n && r < n)
        {
            if (sum == s)
            {
                return {l + 1, r + 1};
            }

            if (sum < s)
            {
                r++;
                sum = sum + arr[r];
            }

            else
            {
                sum = sum - arr[l];
                l++;
                if (l > r)
                {
                    r++;
                    sum = sum + arr[r];
                }
            }
        }
        return {-1};
    }