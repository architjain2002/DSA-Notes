
// optimization of this solution
//  Similar to the naive approach, instead of storing the final merged sorted array,
//  we can keep a counter to keep track of the required position where the median will exist.
//  First, using the median formula, get a position where the median will exist.
//  Then, follow the above approach and instead of storing elements in another array, we will increase the counter value.
//  When the counter value is equal to the median positions, return element.

// here instead of using an array we could only store the middle elements and get our require answers.
#include <bits/stdc++.h>
using namespace std;

float median(int nums1[], int nums2[], int m, int n)
{
    int finalArray[n + m];
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
        {
            finalArray[k++] = nums1[i++];
        }
        else
        {
            finalArray[k++] = nums2[j++];
        }
    }
    if (i < m)
    {
        while (i < m)
            finalArray[k++] = nums1[i++];
    }
    if (j < n)
    {
        while (j < n)
            finalArray[k++] = nums2[j++];
    }
    n = n + m;
    if (n % 2 == 1)
        return finalArray[((n + 1) / 2) - 1];
    else
        return ((float)finalArray[(n / 2) - 1] + (float)finalArray[(n / 2)]) / 2;
}

int main()
{
    int nums1[] = {1, 4, 7, 10, 12};
    int nums2[] = {2, 3, 6, 15};
    int m = sizeof(nums1) / sizeof(nums1[0]);
    int n = sizeof(nums2) / sizeof(nums2[0]);
    cout << "The median of two sorted array is " << fixed << setprecision(5)
         << median(nums1, nums2, m, n);
    return 0;
}