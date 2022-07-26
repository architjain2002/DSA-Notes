void rearrange(long long *arr, int n)
{
    int k = 0, j = n - 1;
    int mx = arr[n - 1] + 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            arr[i] = arr[i] + ((arr[j] % mx) * mx); // for odd index -- max
            j--;
        }
        else
        {
            arr[i] = arr[i] + ((arr[k] % mx) * mx); // for even index -- min
            k++;
        }
    }
    for (int i = 0; i < n; i++)
        arr[i] = arr[i] / mx;
}