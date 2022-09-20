//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int toyCount(int N, int K, vector<int> arr)
    {
        if (K == 0)
            return 0;

        sort(arr.begin(), arr.end());
        int count = 0;
        for (int i = 0; i < N; i++)
        {
            if (K >= arr[i])
            {
                count++;
                K = K - arr[i];
            }
            else
            {
                break;
            }
        }
        return count;
    }
};