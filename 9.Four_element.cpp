
bool find4Numbers(int A[], int n, int X)
{
    sort(A, A + n);

    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            int k = j + 1;
            int end = n - 1;
            while (k < end)
            {

                if (A[i] + A[j] + A[k] + A[end] == X)
                {
                    return true;
                }
                else if (A[i] + A[j] + A[k] + A[end] < X)
                {
                    k++;
                }
                else
                {
                    end--;
                }
            }
        }
    }
    return false;
}