//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    long long countTriplets(long long arr[], int n, long long sum)
    {
        sort(arr, arr + n);
        long long count = 0;
        for (int i = 0; i < n; i++)
        {
            int low = i + 1;
            int high = n - 1;
            while (low < high)
            {
                if (arr[i] + arr[low] + arr[high] < sum)
                {
                    count = count + (high - low);
                    low++;
                }
                else
                {
                    high--;
                }
            }
        }
        return count;
    }
};