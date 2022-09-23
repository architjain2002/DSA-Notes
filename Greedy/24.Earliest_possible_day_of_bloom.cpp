class Solution
{
public:
    static bool cmp(pair<int, int> p1, pair<int, int> p2)
    {
        return p1.second > p2.second;
    }

    int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime)
    {
        vector<pair<int, int>> vec;
        int n = plantTime.size();
        for (int i = 0; i < n; i++)
        {
            vec.push_back({plantTime[i], growTime[i]});
        }

        sort(vec.begin(), vec.end(), cmp);

        int cur = 0;
        int tot = 0;
        for (int i = 0; i < n; i++)
        {
            tot = max(tot, cur + vec[i].first + vec[i].second);
            cur = cur + vec[i].first;
        }

        return tot;
    }
};