class Solution
{
public:
    int longestCommonSum(bool arr1[], bool arr2[], int n)
    {
        // code here
        int v[n];
        for (int i = 0; i < n; i++)
        {
            v[i] = arr1[i] - arr2[i];
        }
        int maxi = 0, sum = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            sum += v[i];
            if (sum == 0)
            {
                maxi = i + 1;
            }
            if (mp.find(sum) != mp.end())
            {
                maxi = max(maxi, i - mp[sum]);
            }
            else
            {
                mp[sum] = i;
            }
        }
        return maxi;
    }
};