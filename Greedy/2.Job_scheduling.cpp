class Solution
{
public:
    // Function to find the maximum profit and the number of jobs done.

    static bool cmp(Job j1, Job j2)
    {
        return j1.profit > j2.profit;
    }

    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, cmp);

        int maxDead = arr[0].dead;
        for (int i = 1; i < n; i++)
        {
            maxDead = max(maxDead, arr[i].dead);
        }

        vector<int> slots(maxDead + 1, -1);

        int count = 0;
        int profit = 0;

        for (int i = 0; i < n; i++)
        {

            for (int j = arr[i].dead; j > 0; j--)
            {

                if (slots[j] == -1)
                {
                    slots[j] = i;
                    count++;
                    profit = profit + arr[i].profit;
                    break;
                }
            }
        }

        return {count, profit};
    }
};