class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int i = 0;
        int maxlen = 0;
        for(int j = 0;j<s.length();j++)
        {
            auto ch = s[j];
            
            i = max(i,mp[ch]);
            
            maxlen = max(maxlen,j-i+1);
            mp[ch] = j + 1;
        }
        return maxlen;
    }
};