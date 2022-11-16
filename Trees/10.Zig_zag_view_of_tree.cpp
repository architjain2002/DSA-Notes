/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node *root)
    {
        deque<Node *> q;
        vector<int> v;
        q.push_back(root);
        v.push_back(root->data);
        Node *temp;

        // set initial level as 1, because root is
        // already been taken care of.
        int l = 1;

        while (!q.empty())
        {
            int n = q.size();

            for (int i = 0; i < n; i++)
            {

                // popping mechanism
                if (l % 2 == 0)
                {
                    temp = q.back();
                    q.pop_back();
                }
                else
                {
                    temp = q.front();
                    q.pop_front();
                }

                // pushing mechanism
                if (l % 2 != 0)
                {

                    if (temp->right)
                    {
                        q.push_back(temp->right);
                        v.push_back(temp->right->data);
                    }
                    if (temp->left)
                    {
                        q.push_back(temp->left);
                        v.push_back(temp->left->data);
                    }
                }
                else if (l % 2 == 0)
                {

                    if (temp->left)
                    {
                        q.push_front(temp->left);
                        v.push_back(temp->left->data);
                    }
                    if (temp->right)
                    {
                        q.push_front(temp->right);
                        v.push_back(temp->right->data);
                    }
                }
            }
            l++; // level plus one
        }
        return v;
    }
};