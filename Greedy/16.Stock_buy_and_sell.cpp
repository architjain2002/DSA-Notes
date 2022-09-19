//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find the days of buying and selling stock for max profit.
    vector<vector<int>> stockBuySell(vector<int> A, int n)
    {

        int s, e;
        vector<vector<int>> ans;
        int buy = 1;

        // buy = 1 means buy is allowed

        for (int i = 0; i < n - 1; i++)
        {
            if (buy)
            {
                if (A[i] < A[i + 1])
                {
                    buy = 0;
                    s = i;
                }
            }
            else
            {
                if (A[i] > A[i + 1])
                {
                    e = i;
                    ans.push_back({s, e});
                    buy = 1;
                }
            }
        }
        // After the end of loop if buy is false then we have to sell last Item for making the profit higher
        if (buy == 0)
        {
            ans.push_back({s, n - 1});
        }
        return ans;
    }