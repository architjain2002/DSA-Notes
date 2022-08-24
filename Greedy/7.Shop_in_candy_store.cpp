class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies,candies+N);
        
        int n = ceil((double) N / (K+1));
        int sum_lo = 0;
        for(int i = 0;i<n;i++)
        {
            sum_lo = sum_lo + candies[i];
        }
        
        
        int sum_hi = 0;
        for(int j = 0 ;j<n;j++)
        {
            sum_hi = sum_hi + candies[N - j -1];
        }
        
        return {sum_lo,sum_hi};
    }
};