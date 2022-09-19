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

// Great explanation of the question and code:
// https://www.youtube.com/watch?v=FdzJmTCVyJU

class Solution
{
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals)
    {

        // Check for the base case. If there are no intervals, return 0
        if (intervals.size() == 0)
        {
            return 0;
        }

        vector<int> start(intervals.size());
        vector<int> end(intervals.size());

        for (int i = 0; i < intervals.size(); i++)
        {
            start[i] = intervals[i].start;
            end[i] = intervals[i].end;
        }

        // Sort the intervals by end time
        sort(end.begin(), end.end());

        // Sort the intervals by start time
        sort(start.begin(), start.end());

        // The two pointers in the algorithm: e_ptr and s_ptr.
        int startPointer = 0, endPointer = 0;

        // Variables to keep track of maximum number of rooms used.
        int count = 0;

        // Variable used to find the final max count
        int ans = 0;

        while (startPointer < intervals.size())
        {
            if (start[startPointer] < end[endPointer])
            {
                count++;
                startPointer++;
            }
            else
            {
                count--;
                endPointer++;
            }

            ans = max(ans, count);
        }
        return ans;
    }
};