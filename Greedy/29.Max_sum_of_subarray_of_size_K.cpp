//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long maximumSumSubarray(int K, vector<int> &Arr, int N)
    {
        int j = 0;
        int i = 0;

        long max_sum = 0;
        long cur_sum = 0;
        while (j < K)
        {
            cur_sum = cur_sum + Arr[j];
            j++;
        }

        max_sum = cur_sum;
        while (j < N)
        {
            cur_sum = cur_sum - Arr[i];
            i++;
            cur_sum = cur_sum + Arr[j];
            j++;
            max_sum = max(max_sum, cur_sum);
        }

        return max_sum;
    }
};