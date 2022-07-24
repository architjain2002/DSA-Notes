class MaxStack
{
public:
    stack<int> st1, st2;
    MaxStack()
    {
        return;
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number)
    {
        st1.push(number);
        if (st2.empty())
        {
            st2.push(number);
        }
        else
        {
            if (number > st2.top())
            {
                st2.push(number);
            }
            else
            {
                st2.push(st2.top());
            }
        }
    }

    /*
     * @return: An integer
     */
    int pop()
    {
        int element = st1.top();
        st1.pop();
        st2.pop();
        return element;
    }

    /*
     * @return: An integer
     */
    int top()
    {
        return st1.top();
    }

    /*
     * @return: An integer
     */
    int peekMax()
    {
        return st2.top();
    }

    /*
     * @return: An integer
     */
    int popMax()
    {
        stack<int> buffer;
        int max = peekMax();
        while (max != top())
        {
            buffer.push(pop());
        }
        pop();
        while (!buffer.empty())
        {
            push(buffer.top());
            buffer.pop();
        }
        return max;
    }
};