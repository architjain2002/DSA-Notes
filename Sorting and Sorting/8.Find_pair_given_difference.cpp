
bool findPair(int arr[], int size, int n)
{
    sort(arr, arr + size);
    int low = 0;
    int high = 1;
    while (low < size - 1 && high < size)
    {
        if (arr[high] - arr[low] == n && high != low)
        {
            return true;
        }
        else if (arr[high] - arr[low] > n)
        {
            low++;
        }
        else
        {
            high++;
        }
    }
    return false;
}