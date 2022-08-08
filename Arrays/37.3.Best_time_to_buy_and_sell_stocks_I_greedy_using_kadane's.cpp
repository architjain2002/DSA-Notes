
/*A more clear explanation on why sum of subarray works.:

Suppose we have original array:
[a0, a1, a2, a3, a4, a5, a6]

what we are given here(or we calculate ourselves) is:
[b0, b1, b2, b3, b4, b5, b6]

where,
b[i] = 0, when i == 0
b[i] = a[i] - a[i - 1], when i != 0

suppose if a2 and a6 are the points that give us the max difference (a2 < a6)
then in our given array, we need to find the sum of sub array from b3 to b6.

b3 = a3 - a2
b4 = a4 - a3
b5 = a5 - a4
b6 = a6 - a5

adding all these, all the middle terms will cancel out except two
i.e.

b3 + b4 + b5 + b6 = a6 - a2

a6 - a2 is the required solution.

so we need to find the largest sub array sum to get the most profit

*/

class Solution
{
public:
    int maxProfit(int prices[], int n)
    {
        int maxCur = 0, maxSoFar = 0;
        for (int i = 1; i < n; i++)
        {
            maxCur += prices[i] - prices[i - 1];

            maxCur = max(0, maxCur);
            maxSoFar = max(maxCur, maxSoFar);
        }
        return maxSoFar;
    }
};