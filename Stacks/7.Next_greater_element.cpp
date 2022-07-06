class Solution
{
public:
    // Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        stack<long> s;
        long *res = new long[n];
        for (int i = n - 1; i >= 0; i--)
        {

            while (!s.empty() && s.top() <= arr[i])
                s.pop();

            res[i] = s.empty() ? -1 : s.top();

            s.push(arr[i]);
        }
        vector<long long> ans;
        for (int i = 0; i < n; i++)
            ans.push_back(res[i]);

        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution obj;
        vector<long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends