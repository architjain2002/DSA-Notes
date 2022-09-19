#include <iostream>
#include <climits>
using namespace std;

int main(int argc, char const *argv[])
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int n;
    int max = INT_MIN;
    cin >> n;
    while (n >= 0)
    {
        if (n > max && n < 100)
        {
            max = n;
        }
        cin >> n;
    }

    if (max == INT_MIN)
    {
        cout << 0;
    }

    else
    {
        cout << max;
    }

    return 0;
}
