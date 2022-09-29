
// https : // www.youtube.com/watch?v=g6OxU-hRGtY

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int nearestTwoPowerBit(int n)
    {
        int count = 0;

        while ((1 << count) <= n)
        {
            count++;
        }

        return count - 1;
    }

    int countBits(int N)
    {
        if (N <= 0)
        {
            return 0;
        }
        if (N == 1)
        {
            return 1;
        }
        int x = nearestTwoPowerBit(N);
        // cout << x;
        return x * pow(2, x - 1) + (N - pow(2, x) + 1) + countBits(N - pow(2, x));
    }
};