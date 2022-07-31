//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the maximum number of activities that can
    // be performed by a single person.

    static int cmp(pair<int, int> PairA, pair<int, int> PairB)
    {
        if (PairA.second < PairB.second)
        {
            return true;
        }
        return false;
    }

    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int, int>> Pair;
        for (int i = 0; i < n; i++)
        {
            Pair.push_back({start[i], end[i]});
        }

        sort(Pair.begin(), Pair.end(), cmp);

        int endpoint = Pair[0].second;
        int count = 1;
        for (int i = 1; i < n; i++)
        {
            // cout << Pair[i].first << " "<<Pair[i].second<<endl;
            if (endpoint < Pair[i].first)
            {
                // cout << Pair[endpoint].first << " "<<Pair[endpoint].second<<endl;
                count++;
                endpoint = Pair[i].second;
            }
        }

        return count;
    }
};