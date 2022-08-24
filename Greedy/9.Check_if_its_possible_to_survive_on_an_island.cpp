//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int minimumDays(int S, int N, int M)
    {
        if (N < M)
            return -1;
        if (S > 6 && 6 * N < 7 * M)
            return -1;
        else
        {
            int total = S * M / N;
            if (S * M % N)
                total++;
            return total;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int S, N, M;
        cin >> S >> N >> M;

        Solution ob;
        cout << ob.minimumDays(S, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends