//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    static bool greater(int a, int b)
    {
        return a > b;
    }

    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N)
    {
        sort(X.begin(), X.end(), greater);

        sort(Y.begin(), Y.end(), greater);

        int total = 0;
        int count_hor = 1;
        int count_ver = 1;
        int i = 0, j = 0;
        while (i < M - 1 && j < N - 1)
        {
            if (X[i] <= Y[j])
            {
                total = total + Y[j] * count_hor;
                count_ver++;
                j++;
            }

            else
            {
                total = total + X[i] * count_ver;
                count_hor++;
                i++;
            }
        }

        for (int ind = i; i < M - 1; i++)
        {
            total = total + count_ver * X[i];
        }

        for (int ind = j; j < N - 1; j++)
        {
            total = total + count_hor * Y[j];
        }
        return total;
    }
};
