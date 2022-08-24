//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    static bool cmp(tuple<int, int, int> t1, tuple<int, int, int> t2)
    {
        return get<1>(t1) < get<1>(t2);
    }

    vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F)
    {
        vector<tuple<int, int, int>> t;
        for (int i = 0; i < N; i++)
        {
            t.push_back(make_tuple(S[i], F[i], i + 1));
        }

        stable_sort(t.begin(), t.end(), cmp);
        vector<int> ans;
        ans.push_back(get<2>(t[0]));

        auto temp = t[0];
        for (int i = 1; i < N; i++)
        {
            if (get<0>(t[i]) > get<1>(temp))
            {
                temp = t[i];
                ans.push_back(get<2>(t[i]));
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};