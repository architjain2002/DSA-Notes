// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        stack<long> s;
        long *res = new long[n];
        for (int i = 0; i < n; i++)
        {

            while (!s.empty() && s.top() <= arr[i])
                s.pop();

            res[i] = s.empty() ? -1 : s.top();

            s.push(arr[i]);
        }
        vector<long long> ans;
        for (int i = 0; i < n; i++)
            ans.push_back(res[i]);

        return ans;
    }
};