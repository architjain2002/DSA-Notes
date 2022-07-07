// { Driver Code Starts
#include <iostream>
#include <vector>
#include <stack>
#include <cctype>
using namespace std;

// Function to find largest rectangular area possible in a given histogram.

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}

long long getMaxArea(long long arr[], int n)
{

    stack<int> st_left;
    int *res_left = new int[n];
    stack<int> st_right;
    int *res_right = new int[n];

    for (int i = 0; i < n; i++)
    {
        while (!st_left.empty() && arr[st_left.top()] >= arr[i])
            st_left.pop();

        res_left[i] = st_left.empty() ? -1 : st_left.top();
        st_left.push(i);

        while (!st_right.empty() && arr[st_right.top()] >= arr[n - i - 1])
            st_right.pop();

        res_right[n - i - 1] = st_right.empty() ? n : st_right.top();
        st_right.push(n - i - 1);
    }
    long long max = LLONG_MIN;
    for (int i = 0; i < n; i++)
    {
        long long area = (res_right[i] - res_left[i] - 1) * arr[i];
        // cout << area << endl;
        if (max < area)
        {
            max = area;
        }
    }

    // print(res_left,n);
    return max;
}

int main(int argc, char const *argv[])
{
    long long *arr = new long long[7];

    arr[0] = 6;
    arr[1] = 2;
    arr[2] = 5;
    arr[3] = 4;
    arr[4] = 5;
    arr[5] = 1;
    arr[6] = 6;
    cout << getMaxArea(arr, 7);
    return 0;
}