class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {

        ios_base ::sync_with_stdio(false);
        cin.tie(nullptr);
        int i = 0;
        int len = p.length();
        int j = len - 1;
        vector<int> ans;

        sort(p.begin(), p.end());
        while (j < s.length())
        {
            string mini_str = s.substr(i, len);
            sort(mini_str.begin(), mini_str.end());

            if (mini_str.compare(p) == 0)
            {
                ans.push_back(i);
            }
            i++;
            j++;
        }
        return ans;
    }
};