class Solution
{
    vector<TreeNode *> helper(int n)
    {
        vector<TreeNode *> trees;
        if (n == 0)
        {
            trees.push_back(NULL);
            return trees;
        }
        if (n == 1)
        {
            TreeNode *temp = new TreeNode(0);
            trees.push_back(temp);
            return trees;
        }
        // lets say we have x nodes then we will keep one for root and x-1 for left and right
        for (int i = 0; i <= n - 1; i++)
        {
            int leftCount = i;
            int rightCount = n - 1 - i;
            // we can only have odd numbers on left hand side and right hand side toherwise full binary tree is not possible
            if (left % 2 != 0 && right % 2 != 0)
            {
                // say there are l ways to construct full binary tree from n = i for left hand side
                // and there are r ways to construct full binary tree from n - 1 - i for left hand side
                // then our ans will have combination for each left and each right adding root to it
                vector<TreeNode *> leftTrees = helper(left);
                vector<TreeNode *> rightTrees = helper(right);
                for (TreeNode *leftTree : leftTrees)
                {
                    for (TreeNode *rightTree : rightTrees)
                    {
                        TreeNode *root = new TreeNode(0);
                        root->left = leftTree;
                        root->right = rightTree;
                        trees.push_back(root);
                    }
                }
            }
        }
        return trees;
    }

public:
    vector<TreeNode *> allPossibleFBT(int N)
    {
        return helper(N);
    }
};