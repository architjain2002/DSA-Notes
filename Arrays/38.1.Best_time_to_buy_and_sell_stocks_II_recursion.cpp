class Solution
{
public:
    int find(int ind, vector<int> &v, bool buy)
    {
        if (ind >= v.size())
            return 0;

        if (buy) // if we are buying then next time we will sell else next time we will buy
        {        //-prices[i], because bought stock of prices[i], expend money, !buy because next time sell

            return max(-v[ind] + find(ind + 1, v, !buy), find(ind + 1, v, buy));
        }
        else // it's time to sell
        {    //+prices[i], because we now gain (i.e) sell our stock at rate of prices[i]

            return max(v[ind] + find(ind + 1, v, !buy), find(ind + 1, v, buy));
        }
    }
    int maxProfit(vector<int> &prices)
    {

        int n = prices.size();
        if (n < 2)
            return 0;
        // passing here buy=1 because we will first buy then sell
        return find(0, prices, 1);
    }
};