Node *solve(int in[], int post[], int n, int inStart, int inEnd, int postStart, int postEnd, map<int, int> &mp)
{

    if (inStart > inEnd || postStart > postEnd)
        return nullptr;

    Node *node = new Node(post[postEnd]);
    int ind = mp[post[postEnd]];
    int right = inEnd - ind;

    node->left = solve(in, post, n, inStart, ind - 1, postStart, postEnd - right - 1, mp);
    node->right = solve(in, post, n, ind + 1, inEnd, postEnd - right, postEnd - 1, mp);
    return node;
}

Node *buildTree(int in[], int post[], int n)
{
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[in[i]] = i;
    }

    return solve(in, post, n, 0, n - 1, 0, n - 1, mp);
}