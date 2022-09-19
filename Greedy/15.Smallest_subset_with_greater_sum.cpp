//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int minSubset(vector<int> &arr, int N)
    {
        long long sum = 0;

        sort(arr.begin(), arr.end());

        for (int i = 0; i < N; i++)

            sum += arr[i];

        long long c = 0;

        long long prev = 0;

        for (int i = N - 1; i >= 0; i--)

        {

            sum -= arr[i];

            prev += arr[i];

            c++;

            if (prev > sum)

            {

                return c;
            }
        }
    }
};