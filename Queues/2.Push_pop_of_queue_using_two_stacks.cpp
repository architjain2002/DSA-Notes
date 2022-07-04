void StackQueue ::push(int x)
{
    s1.push(x);
}

// Function to pop an element from queue by using 2 stacks.
int StackQueue ::pop()
{
    if (s1.empty())
        return -1;
    if (s1.size() == 1)
    {
        int ans = s1.top();
        s1.pop();
        return ans;
    }

    int x = s1.top();
    s1.pop();
    int ans = pop();
    s1.push(x);
    return ans;
}
