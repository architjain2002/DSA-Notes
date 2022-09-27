//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// Time Complexity: O(n*log(log(n)))

// Auxiliary Space : O(n)
class Solution
{
public:
    vector<int>
    sieveOfEratosthenes(int N)
    {
        bool prime[N + 1];
        memset(prime, true, sizeof(prime));

        for (int p = 2; p * p < N; p++)
        {
            if (prime[p] == true)
            {
                for (int i = p * p; i <= N; i = i + p)
                {
                    prime[i] = false;
                }
            }
        }
        vector<int> vec;

        for (int i = 2; i <= N; i++)
        {
            if (prime[i] == true)
            {
                vec.push_back(i);
            }
        }
        return vec;
    }
};