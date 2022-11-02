bool wordBreak(string s, vector<string> &wordDict)
{
    set<string> dict(wordDict.begin(), wordDict.end());
    return f(0, s, dict);
}

bool f(int ind, string &s, set<string> &dict)
{
    if (ind == s.length())
        return true;

    for (int i = ind; i < s.length(); i++)
    {
        string cur = s.substr(ind, i - ind + 1);
        if (dict.find(cur) != dict.end() && f(i + 1, s, dict))
        {
            return true;
        }
    }
    return false;
}