class Solution
{
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>> &intervals)
    {
        vector<vector<int>> answer;
        sort(intervals.begin(), intervals.end()); // according to starting time
        int mn = intervals[0][0];
        int mx = intervals[0][1];
        for (int i = 0; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= mx)
            {
                mx = max(mx, intervals[i][1]);
            }
            else
            {
                answer.push_back({mn, mx});
                mn = intervals[i][0];
                mx = intervals[i][1];
            }
        }

        answer.push_back({mn, mx});
        return answer;
    }
};