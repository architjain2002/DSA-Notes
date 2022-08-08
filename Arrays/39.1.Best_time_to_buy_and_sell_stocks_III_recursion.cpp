class Solution
{
public:
    int find(vector<int> &prices, int ind, bool buy, int c)
    {
        // if buy =1 means we have to buy now
        // else we have to sell now
        if (ind >= prices.size() || c >= 2)
            return 0; // counter

        if (buy) // now we can either buy prices[i] or we can skip it and try next to buy
        {
            return max(-prices[ind] + find(prices, ind + 1, !buy, c), find(prices, ind + 1, buy, c));
        }
        else // now we can either sell prices[i] or we can skip it and try next to sell
        {
            return max(prices[ind] + find(prices, ind + 1, !buy, c + 1), find(prices, ind + 1, buy, c));
        }
    }
    int maxProfit(vector<int> &prices)
    {
        return find(prices, 0, 1, 0);
    }
};