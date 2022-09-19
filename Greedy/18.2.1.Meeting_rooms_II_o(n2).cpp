/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution
{
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    static bool cmp(Interval i1, Interval i2)
    {
        return i1.start < i2.start;
    }
    int minMeetingRooms(vector<Interval> &intervals)
    {
        if (intervals.size() == 0)
            return 0;
        if (intervals.size() == 1)
            return 1;

        sort(intervals.begin(), intervals.end(), cmp);
        int count = 0;
        vector<int> end_meeting_room;
        for (int i = 0; i < intervals.size(); i++)
        {
            int j = 0;
            for (j = 0; j < end_meeting_room.size(); j++)
            {
                if (intervals[i].start >= end_meeting_room[j])
                {
                    end_meeting_room[j] = max(intervals[i].end, end_meeting_room[j]);
                    break;
                }
            }

            if (j == end_meeting_room.size())
            {
                end_meeting_room.push_back(intervals[i].end);
                count++;
            }
        }
        return count;
    }
};