class Solution
{
    string curr;
    vector<string> ans;
    unordered_map<int, string> mp;
    void helper(string &digits, int index)
    {
        if (index == digits.length())
        {
            ans.push_back(curr);
            return;
        }
        string chrs = mp[digits[index] - 48];
        for (char c : chrs)
        {
            curr.push_back(c);
            helper(digits, index + 1);
            curr.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        ios_base ::sync_with_stdio(false);
        cin.tie(nullptr);

        if (digits.length() == 0)
            return ans;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        helper(digits, 0);
        return ans;
    }
};