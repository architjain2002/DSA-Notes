// O(logn) solution

int Square(int n)
{
    if (n == 0) //  squre of 0 is 0
        return 0;

    if (n < 0) // to handle negative numbers
    {
        n = -n;
    }

    if (n & 1) // for odd number
    {
        return (Square(n) << 2) + (x << 2) + 1;
    }
    else // for even number
    {
        return (Square(n) << 2);
    }
}