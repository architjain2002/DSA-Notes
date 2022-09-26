class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();

        vector<int> prefix(n, 0);
        prefix[0] = cardPoints[0];
        for (int i = 1; i < cardPoints.size(); i++)
        {
            prefix[i] = prefix[i - 1] + cardPoints[i];
        }

        if (n == k)
            return prefix[n - 1];
        if (k == 1)
            return max(cardPoints[0], cardPoints[n - 1]);

        int curr = prefix[k - 1];
        int maxval = curr;
        int j = 1;
        for (int i = k - 2; i >= 0; i--)
        {
            curr = prefix[i] + prefix[n - 1] - prefix[n - j - 1];
            j++;
            maxval = max(maxval, curr);
        }

        maxval = max(maxval, prefix[n - 1] - prefix[n - k - 1]);
        return maxval;
    }
};