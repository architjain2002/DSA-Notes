// Function to find the smallest divisor
int smallestDivisor(int n)
{
    // if divisible by 2
    if (n % 2 == 0)
        return 2;

    // iterate from 3 to sqrt(n)
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return i;
    }

    return n;
}