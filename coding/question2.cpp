#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
using namespace std;

int countDigit(int n)
{
    return floor(log10(n) + 1);
}

void processArray(vector<int> arr)
{
    int min = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        if (countDigit(arr[i]) != 2)
        {
            cout << arr[i] << endl;
            continue;
        }
        int j = i;

        while (countDigit(arr[j]) == 2)
        {
            if (arr[j] < min)
            {
                min = arr[j];
            }
            j++;
        }
        j--;
        cout << min << endl;
        min = INT_MAX;
        i = j;
    }
}

int main(int argc, char const *argv[])
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int n;
    cin >> n;
    vector<int> v;
    while (n >= 0)
    {
        v.push_back(n);
        cin >> n;
    }

    processArray(v);

    return 0;
}