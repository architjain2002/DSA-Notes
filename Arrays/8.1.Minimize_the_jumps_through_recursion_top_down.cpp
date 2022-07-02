// https://gist.github.com/nateshmbhat/4ab6ccef6dcb51c0651d1cc9f2f86f92

#include <iostream>
#include <cstring>
using namespace std;

int dp[10000];
int minJumps(int arr[], int l, int h)

{

    // Base case: when source and destination are same

    if (h == l)

        return 0;

    // When nothing is reachable from the given source

    if (arr[l] == 0)

        return INT_MAX;

    if (dp[l] != -1) // to check whether already present
        return dp[l];
    // Traverse through all the points reachable from arr[l]. Recursively

    // get the minimum number of jumps needed to reach arr[h] from these

    // reachable points.

    int min = INT_MAX;

    for (int i = l + 1; i <= h && i <= l + arr[l]; i++)

    {

        int jumps = minJumps(arr, i, h);

        if (jumps != INT_MAX && jumps + 1 < min)

            min = jumps + 1;
    }

    return dp[l] = min;
}
int main(void)
{
    int N = 11;
    int arr[100] = {1, 3, 1, 4, 0, 1, 2, 1, 6, 0, 9};

    // int N = 5; // test case
    // int arr[100] = {1, 1, 1, 1, 4};
    memset(dp, -1, sizeof(dp));
    int x = minJumps(arr, 0, N - 1);
    if (x == INT_MAX)
    {
        cout << "-1";
    }
    else
    {
        cout << x << endl;
    }
}