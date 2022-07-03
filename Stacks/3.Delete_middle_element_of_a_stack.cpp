
class Solution
{
public:
    // Function to delete middle element of a stack.

    void pop_middle(stack<int> &s, int middleIndex)
    {
        if (middleIndex == 0)
        {
            s.pop();
            return;
        }

        else
        {
            int temp = s.top();
            s.pop();
            middleIndex--;
            pop_middle(s, middleIndex);

            s.push(temp);
            return;
        }
    }

    void deleteMid(stack<int> &s, int sizeOfStack)
    {
        int middleIndex = ceil((float)(sizeOfStack + 1) / 2) - 1;

        pop_middle(s, middleIndex);
        return;
    }
};