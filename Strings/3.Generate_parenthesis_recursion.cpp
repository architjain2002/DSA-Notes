class Solution
{
public:
    void solve(int count1, int count2, int max, string str, vector<string> &ans)
    {
        if (str.length() == 2 * max)
        {
            ans.push_back(str);
            return;
        }

        if (count1 < max)
            solve(count1 + 1, count2, max, str + '(', ans);
        if (count2 < count1)
            solve(count1, count2 + 1, max, str + ')', ans);
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        solve(0, 0, n, "", ans);
        return ans;
    }
};