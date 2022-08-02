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
        int square = 0;

        while (square < N)
        {
            square = i * i;
            i++;
        }
        return i;
    }
};