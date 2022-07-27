
int jump(int A[], int n)
{
    int jumps = 0, curEnd = 0, curFarthest = 0;
    for (int i = 0; i < n - 1; i++)
    {
        curFarthest = max(curFarthest, i + A[i]);
        if (i == curEnd)
        {
            jumps++;
            curEnd = curFarthest;
        }
    }
    return jumps;
}