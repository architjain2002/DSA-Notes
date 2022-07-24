#include <iostream>
using namespace std;
bool check(string str, int M)
{
    if (((str[str.length() - 1] - '0') % 2 == 1) && (((str[0] - '0') % 2) == 0) && str.length() >= M)
    {
        return true;
    }
    else
        return false;
}

void part(int N, int M, int K, string S, int j, int &counting)
{
    if (K == 0)
    {
        counting = counting + 1;
        return;
    }

    for (int k = j; k <= S.length() - j; k++)
    {
        string str1 = S.substr(0, k);
        string rem = S.substr(k, S.length() - 1);
        if (check(str1, j) == true && check(rem, j) == true)
        {

            cout << str1 << " " << rem << endl;
            part(rem.length(), M, K - 1, rem, j, counting);
        }
    }
    return;
}

long long solve(int N, int M, int K, string S)
{
    int counting = 0;
    part(N, M, K - 1, S, M, counting);
    return counting;
}

int main(int argc, char const *argv[])
{
    // string S = "232387421";
    // int N = S.length();
    // int M = 2;
    // int K = 3;

    string S = "2453231211";
    int N = S.length();
    int M = 3;
    int K = 3;
    cout << solve(N, M, K, S);
    return 0;
}
