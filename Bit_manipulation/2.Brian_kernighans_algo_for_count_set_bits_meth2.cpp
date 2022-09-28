unsigned int countSetBits(unsigned int n)
{
    unsigned int count = 0;
    while (n)
    {
        n = n & n - 1;
        count++;
    }
    return count;
}