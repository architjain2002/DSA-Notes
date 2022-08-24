//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        sort(a, a + n);
        for (int i = 0; i < n; i++)
        {
            if (k)
            {
                if (a[i] < 0)
                    a[i] *= -1;
                else
                    break;
                k--;
            }
        }
        sort(a, a + n);
        if (k % 2)
            return accumulate(a + 1, a + n, 0) - a[0];
        return accumulate(a, a + n, 0);
    }
};