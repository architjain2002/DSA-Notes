class Solution
{

public:
    Node *buildTree(int preorder[], int preStart, int preEnd, int inorder[], int inStart, int inEnd, map<int, int> &inMap)
    {
        if (preStart > preEnd || inStart > inEnd)
            return NULL;
        Node *root = new Node(preorder[preStart]);
        int inRoot = inMap[root->data];
        int numsLeft = inRoot - inStart;
        root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
        root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);
        return root;
    }
    Node *buildTree(int in[], int pre[], int n)
    {
        // Code here
        map<int, int> inMap;
        for (int i = 0; i < n; i++)
        {
            inMap[in[i]] = i;
        }
        Node *root = buildTree(pre, 0, n - 1, in, 0, n - 1, inMap);
        return root;
    }
};