class Solution
{
public:
    int find(vector<int> &prices, int ind, bool buy, int c, int k)
    { // if buy =1 means we have to buy now
        // else we have to sell now
        if (ind >= prices.size() || c >= k)
            return 0; // counter

        if (buy) // now we can either buy prices[i] or we can skip it and try next to buy
        {
            return max(-prices[ind] + find(prices, ind + 1, !buy, c, k), find(prices, ind + 1, buy, c, k));
        }
        else // now we can either sell prices[i] or we can skip it and try next to sell
        {
            return max(prices[ind] + find(prices, ind + 1, !buy, c + 1, k), find(prices, ind + 1, buy, c, k));
        }
    }
    int maxProfit(int k, vector<int> &prices)
    {

        // edge case we are not able to pick 2k points from n points, which means
        // we will not reach the limit no matter how we try.
        // if the price of day i arise, buy the stock in i-1th day and sell it at ith day.
        if (2 * k > prices.size())
        {
            int res = 0;
            for (int i = 1; i < prices.size(); i++)
            {
                res += max(0, prices[i] - prices[i - 1]);
            }
            return res;
        }

        // here we can do maximum k transaction
        return find(prices, 0, 1, 0, k);
    }
};