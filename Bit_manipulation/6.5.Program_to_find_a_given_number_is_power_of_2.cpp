// O(1) optimal solution
bool isPowerofTwo(long long n)
{
    return (n != 0) && ((n & ~(n - 1)) == n);
}