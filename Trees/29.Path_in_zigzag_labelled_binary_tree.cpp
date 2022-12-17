class Solution
{
public:
    vector<int> pathInZigZagTree(int label)
    {
        stack<int> st;
        st.push(label);
        while (label != 1)
        {
            int level = log2(label);
            int bin = pow(2, level);
            if (label % 2 == 0)
            {
                int ind = (label - bin) / 2 + 1;
                int tx = 1 + (ind - 1) * 3;
                label = label - tx;
                st.push(label);
            }
            else
            {
                int ind = (label - (bin + 1)) / 2 + 1;
                int tx = 2 + (ind - 1) * 3;
                label = label - tx;
                st.push(label);
            }
        }
        vector<int> vec;
        while (!st.empty())
        {
            vec.push_back(st.top());
            st.pop();
        }
        return vec;
    }
};