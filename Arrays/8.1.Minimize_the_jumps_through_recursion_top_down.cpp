// https://gist.github.com/nateshmbhat/4ab6ccef6dcb51c0651d1cc9f2f86f92

#include <iostream>
#include <cstring>
using namespace std;
int dp[10000][10000]; // dp[i][sum]
int solveTopDown(int i, int arr[], int n, int sum)
{
    if (i >= n - 1)
        return sum;
    if (dp[i][sum] > 0)
        return dp[i][sum];

    int res = INT_MAX;

    for (int j = 1; j <= arr[i]; j++)
    {
        res = min(res, solveTopDown(i + j, arr, n, sum + 1));
    }
    // cout << res << endl;
    return dp[i][sum] = res;
}

int main(void)
{
    int N = 11;
    int arr[100] = {1, 3, 5, 0, 0, 1, 6, 7, 6, 0, 9};

    // int N = 5; // test case
    // int arr[100] = {1, 1, 2, 0, 4};

    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < N; i++)
    {
        dp[i][0] = INT_MAX;
    }
    for (int i = 0; i < N; i++)
    {
        dp[0][i] = 0;
    }

    int x = solveTopDown(0, arr, N, 0);
    if (x == INT_MAX)
    {
        cout << "-1";
    }
    else
    {
        cout << x << endl;
    }
}