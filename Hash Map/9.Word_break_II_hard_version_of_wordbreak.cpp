class Solution
{
    void solve(int index, string &s, unordered_set<string> &hashset, int &n, string sub_ans, vector<string> &ans)
    {
        if (index == n)
        {
            sub_ans = sub_ans.substr(1); // to remove leading space
            ans.push_back(sub_ans);
            return;
        }
        string temp = "";
        // tring every possible partition
        for (int i = index; i < n; i++)
        {
            // temp is the word formed by partition
            temp += s[i];
            // if word before partition exist in hashset then check for remaining word
            if (hashset.find(temp) != hashset.end())
            {
                solve(i + 1, s, hashset, n, sub_ans + " " + temp, ans);
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        vector<string> ans; // answer vector
        // storing all the words in hashset
        unordered_set<string> hashset;
        for (auto i : wordDict)
        {
            hashset.insert(i);
        }
        int n = s.length();
        string sub_ans = "";                   // empty string to store sentence
        solve(0, s, hashset, n, sub_ans, ans); // helpercode call
        return ans;
    }
};