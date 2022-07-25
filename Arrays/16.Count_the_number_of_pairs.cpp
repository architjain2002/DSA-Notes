//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int getPairsCount(int arr[], int n, int k)
    {
        unordered_map<int, int> mp; // we do not use ordered map coz the insertion an other operations are O(n)
        int answer = 0;

        for (int i = 0; i < n; i++)
        {
            int temp = k - arr[i]; // b = k - a
            if (mp.find(temp) != mp.end())
            {
                answer = answer + mp[temp];
            }
            mp[arr[i]]++;
        }
        return answer;
    }
};