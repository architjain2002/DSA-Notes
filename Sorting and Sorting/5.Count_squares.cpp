class Solution
{
public:
    int countSquares(int N)
    {
        if (N == 0 || N == 1)
        {
            return 0;
        }
        int i = 1;
        int square = 1;

        while (square < N)
        {
            i++;
            square = i * i;
        }
        return i - 1;
    }
};