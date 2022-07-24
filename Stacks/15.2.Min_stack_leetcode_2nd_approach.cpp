class MinStack
{
public:
    stack<int> st1, st2;
    void push(int val)
    {
        st1.push(val);
        if (st2.empty())
        {
            st2.push(val);
        }
        else
        {
            if (st2.top() <= val)
            {
                st2.push(st2.top());
            }
            else
            {
                st2.push(val);
            }
        }
    }

    void pop()
    {
        if (st1.empty())
        {
            return;
        }
        st1.pop();
        st2.pop();
    }

    int top()
    {
        return st1.top();
    }

    int getMin()
    {
        return st2.top();
    }
};

/*
*MinStack *obj = new MinStack();
*obj->push(val);
*obj->pop();
*int param_3 = obj->top();
*int param_4 = obj->getMin();
* /