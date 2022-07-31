//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    long long smallestpositive(vector<long long> array, int n)
    {
        sort(array.begin(), array.end());

        long long ans = 1;
        for (int i = 0; i < n; i++)
        {
            if (array[i] > ans)
            {
                return ans;
            }
            ans = ans + array[i];
        }

        return ans;
    }
};