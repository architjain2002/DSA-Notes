
// This solution has a time complexity of O(n) and a space complexity of O(n) * O(n) becuase of function stack
class Solution
{
public:
    vector<int> ans;
    vector<int> Reverse(stack<int> st)
    {
        if (st.empty())
        {
            return ans;
        }

        ans.push_back(st.top());
        st.pop();
        return Reverse(st);
    }
};