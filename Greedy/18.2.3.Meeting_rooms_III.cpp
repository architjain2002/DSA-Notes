class Solution
{
public:
    /**
     * @param intervals: the intervals
     * @param rooms: the sum of rooms
     * @param ask: the ask
     * @return: true or false of each meeting
     */
    vector<bool> meetingRoomIII(vector<vector<int>> &intervals, int rooms, vector<vector<int>> &ask)
    {
        vector<int> sum(50002, 0);
        vector<int> vis(50002, 0);

        int maxn = 0;
        for (int i = 0; i < intervals.size(); i++)
        {
            vis[intervals[i][0]]++; // to mark starting point
            vis[intervals[i][1]]--; // to mark ending point

            maxn = max(maxn, intervals[i][1]); // to find the max interval of the entire meetings
        }

        for (int i = 0; i < ask.size(); i++)
        {
            maxn = max(maxn, ask[i][1]); // again to update the ending time fo the ask meetings as well
        }

        sum[0] = 0;
        int temp = 0;

        // to mark only the filled(1) times and unfilled time(0)

        // so basically after this what we obtain is sum array with 1s and 0s and the new intervals can be filled only
        // at 0s and between the two 1s.

        for (int i = 1; i < maxn; i++)
        {
            temp = temp + vis[i];
            if (temp < rooms)
            {
                sum[i] = 0;
            }
            else
            {
                sum[i] = 1;
            }
        }

        // this is prefix sum
        // as we need to fill between the 1s it will take O(n2) to do so hence
        // using prefix sum we obtain the subarrays with similar number consecutively and we can insert only if the interval in ask
        // array corresponds to the same elements

        vector<bool> ans;
        for (int i = 1; i < maxn; i++)
        {
            sum[i] = sum[i] + sum[i - 1];
        }

        for (int i = 0; i < ask.size(); i++)
        {
            if (sum[ask[i][0] - 1] == sum[ask[i][1] - 1])
            {
                ans.push_back(true);
            }

            else
            {
                ans.push_back(false);
            }
        }
        return ans;
    }
};