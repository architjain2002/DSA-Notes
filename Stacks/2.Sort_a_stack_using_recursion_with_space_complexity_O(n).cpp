void insert_middle_sorted(int data, stack<int> &st)
{
    if (st.empty())
    {
        st.push(data);
        return;
    }
    int temp = st.top();
    if (temp > data)
    {
        st.pop();
        insert_middle_sorted(data, st);
        st.push(temp);
        return;
    }
    else
    {
        st.push(data);
        return;
    }
}

void SortedStack ::sort()
{
    if (!s.empty())
    {
        int temp = s.top();
        s.pop();
        sort();
        insert_middle_sorted(temp, s);
    }
}
