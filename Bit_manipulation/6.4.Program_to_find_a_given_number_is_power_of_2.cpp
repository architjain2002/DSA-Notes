// brian kirningham algorithm to find a given number is power of 2 or not
// O(1) optimal solution
bool isPowerofTwo(long long n)
{
    return (n != 0) && ((n & (n - 1)) == 0);
}