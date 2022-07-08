// this problem is very similar to(or rather the application of next greater element to left)

class Solution
{
public:
    // Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(int price[], int n)
    {

        vector<int> res;
        stack<int> st;
        res.push_back(1);
        st.push(0);
        for (int i = 1; i < n; i++)
        {
            while (!st.empty() && price[st.top()] <= price[i])
            {
                st.pop();
            }

            res.push_back(st.empty() ? i + 1 : i - st.top());
            st.push(i);
        }
        return res;
    }
};