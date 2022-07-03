// This solution has a time complexity of O(n*n) and a space complexity of O(n)
// becuase of function stack but the same stack is reused hence we optimize the space
#include <iostream>
#include <stack>

using namespace std;

stack<int> st;

// Below is a recursive function
// that inserts an element
// at the bottom of a stack.
void insert_back(int data)
{

    if (st.empty())
    {
        st.push(data);
        return;
    }
    // All items are held in Function Call
    // Stack until we reach end of the stack
    // When the stack becomes empty, the
    // st.size() becomes 0, the above if
    // part is executed and the item is
    // inserted at the bottom
    int temp = st.top();
    st.pop();
    insert_back(data);

    // push allthe items held in
    // Function Call Stack
    // once the item is inserted
    // at the bottom
    // backtrack type step
    st.push(temp);
    return;
}

// Below is the function that
// reverses the given stack using
// insert_at_bottom()
void reverse()
{
    if (!st.empty())
    {
        int temp = st.top();
        st.pop();
        reverse();
        insert_back(temp);
    }
}

int main()
{
    st.push(1);
    st.push(2);
    st.push(3);
    reverse(); // this reverses
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}