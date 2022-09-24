int findMax(int n, int m, int a[], int b[], int k[])
{
    // Your code goes here
    int arr[n] = {0}; // arr[] = {0,0,0,0,0};

    // a[] : shows lowerBound where we have to start up to iterate;
    // b[] : shows uperBound where we have to end our iteration;

    for (int i = 0; i < m; i++)
    {
        int lb = a[i];
        int ub = b[i];
        arr[lb] += k[i];
        arr[ub + 1] -= k[i];

        // let's try to get this with an example :
        // i=0 : arr[] becomes  [100,0,-100,0,0]
        // i=1 : 100,100,-100,0,0
        // i=2 : 100,100,0,0,-100
    }

    int res = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        arr[i] += arr[i - 1];
        // In this we make our array as condition says :
        // i=1 : 100,200,0,0,-100
        // i=2 : 100,200,200,0,-100
        // i=3 : 100,200,200,200,-100
        // i=4 : 100,200,200,200,100
    }
    return *max_element(arr, arr + n); // according to question we have to return maximum value from array
}