class Solution
{
public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n)
    {
        int prefix[n];

        prefix[0] = a[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + a[i];
        }

        for (int i = 1; i < n; i++)
        {
            if (prefix[i] - a[i] == (prefix[n - 1] - prefix[i]))
            {
                return i + 1;
            }
        }
        return -1;
    }
};