bool wordBreak(string s, vector<string> &wordDict)
{
    set<string> dict(wordDict.begin(), wordDict.end());
    int n = s.length();
    vector<bool> dp(n + 1, false);
    dp[n] = true;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int i = ind; i < s.length(); i++)
        {
            string cur = s.substr(ind, i - ind + 1);
            if (dict.find(cur) != dict.end() && dp[i + 1])
            {
                dp[ind] = true;
                break;
            }
        }
    }
    return dp[0];
}