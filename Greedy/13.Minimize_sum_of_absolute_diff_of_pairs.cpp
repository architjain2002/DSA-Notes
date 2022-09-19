//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    long long findMinSum(vector<int> &A, vector<int> &B, int N)
    {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        long long diff = 0;
        for (int i = 0; i < N; i++)
        {
            diff = diff + abs(A[i] - B[i]);
        }
        return diff;
    }
};