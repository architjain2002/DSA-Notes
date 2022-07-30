//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    // The main function that returns the arrangement with the largest value as
    // string.
    // The function accepts a vector of strings

    static bool cmp(string a, string b)
    {
        return ((a + b) > (b + a));
    }
    string printLargest(vector<string> &arr)
    {
        sort(arr.begin(), arr.end(), cmp);
        string ans = "";
        for (int i = 0; i < arr.size(); i++)
        {
            ans = ans.append(arr[i]);
        }
        return ans;
    }
};