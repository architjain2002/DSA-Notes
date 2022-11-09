class Solution
{
public:
    void solve(string str)
    {
        int n = str.length();

        if (n < 2)
            return -1;
        int i = n / 2 - 1;
        int j = n - 1;

        while (i > 0)
        {
            if (str[i] != str[j])
            {
                if (j != n - 1)
                {
                    j = n - 1;
                }
                else
                {
                    i--;
                }
            }
            else
            {
                i--;
                j--;
            }
        }
        return n - j - 1;
    }
};