// O(logn) as log2 function takes O(logn)

bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;

    return (ceil(log2(n)) == floor(log2(n))); // log2(n) == natural number
}