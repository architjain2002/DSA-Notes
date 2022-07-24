class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> st;
        int *answer = new int[temperatures.size()];
        for (int i = temperatures.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && temperatures[st.top()] <= temperatures[i])
            {
                st.pop();
            }

            answer[i] = st.empty() ? 0 : st.top() - i;
            st.push(i);
        }
        vector<int> res;
        for (int i = 0; i < temperatures.size(); i++)
        {
            res.push_back(answer[i]);
        }
        return res;
    }
};