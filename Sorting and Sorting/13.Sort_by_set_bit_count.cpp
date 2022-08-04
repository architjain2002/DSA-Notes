class Solution
{
public:
    static bool cmp(int a, int b)
    {
        unsigned long long count1 = 0;
        unsigned long long count2 = 0;
        while (a)
        {

            count1 = count1 + (a & 1);
            a = a >> 1;
        }
        while (b)
        {

            count2 = count2 + (b & 1);
            b = b >> 1;
        }

        return count1 > count2;
    }

    void sortBySetBitCount(int arr[], int n)
    {
        stable_sort(arr, arr + n, cmp);
        return;
    }
}