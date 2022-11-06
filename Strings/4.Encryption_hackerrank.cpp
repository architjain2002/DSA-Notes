#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string encryption(string s)
{
    string s_no_space = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
            continue;
        s_no_space = s_no_space + s[i];
    }
    int row = floor(sqrt(s_no_space.length()));
    int col = ceil(sqrt(s_no_space.length()));

    if (row * col < s_no_space.length())
    {
        row = row + 1;
    }

    vector<string> grid(col);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            grid[i] = grid[i] + s[i * col + j];
        }
    }

    string ans = "";

    // for(int i =0;i<row;i++)
    // {
    //     for(int j = 0;j<col;j++)
    //     {
    //         cout << grid[i][j];
    //     }
    //     cout<<endl;
    // }
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (grid[j][i] == '\0')
                break;
            ans = ans + grid[j][i];
        }
        ans = ans + " ";
    }
    return ans.substr(0, s_no_space.length() + col - 1);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}