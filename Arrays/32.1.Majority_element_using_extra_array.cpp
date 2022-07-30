//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {

        int arr[1000 * 1000] = {0};
        for (int i = 0; i < size; i++)
        {
            arr[a[i]]++;
        }
        int half = size / 2 + 1;
        for (int i = 0; i < 1000000; i++)
        {
            if (arr[i] >= half)
            {
                return i;
            }
        }

        return -1;
    }
};