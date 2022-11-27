class Solution
{
public:
    int checkMirrorTree(int n, int e, int arr[], int brr[])
    {

        unordered_map<int, stack<int>> m;

        for (int i = 0; i < 2 * e; i += 2)
        {

            m[arr[i]].push(arr[i + 1]);
        }

        for (int i = 0; i < 2 * e; i += 2)
        {

            if (m[brr[i]].top() != brr[i + 1])
                return 0;

            else
                m[brr[i]].pop();
        }

        return 1;
    }
};