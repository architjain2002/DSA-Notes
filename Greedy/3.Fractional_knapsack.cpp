class Solution
{
public:
    // Function to get the maximum total value in the knapsack.

    static bool cmp(Item i1, Item i2)
    {
        return (double)i1.value / i1.weight > (double)i2.value / i2.weight;
    }

    double fractionalKnapsack(int W, Item arr[], int n)
    {

        sort(arr, arr + n, cmp);

        double wt = 0;
        double val = 0;
        int curr = 0;
        for (int i = 0; i < n; i++)
        {
            if (wt < W)
            {
                curr = i;
                wt = wt + arr[i].weight;
                val = val + arr[i].value;
            }

            else
                break;
        }
        if (wt > W)
        {
            wt = wt - arr[curr].weight;
            val = val - arr[curr].value;

            val += (arr[curr].value / (double)arr[curr].weight) * (W - wt);
            return val;
        }

        else
        {
            return val;
        }
    }
};