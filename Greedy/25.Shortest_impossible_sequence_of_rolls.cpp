class Solution
{
public:
    int shortestSequence(vector<int> &rolls, int k)
    {
        unordered_map<int, int> mp;

        int count = 0;
        int ans = 0;
        for (int i = 0; i < rolls.size(); i++)
        {
            mp[rolls[i]]++;
            if (mp[rolls[i]] == 1)
                count++;

            if (count == k)
            {
                count = 0;
                mp.clear();
                ans++;
            }
        }
        return ans + 1;
    }
};