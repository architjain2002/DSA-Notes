/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node *random;
};
*/

class Solution
{
public:
    /* The function should clone the passed tree and return
       root of the cloned tree */

    unordered_map<Node *, Node *> mp;

    void cloner(Node *root, Node *root2)
    {

        if (root == nullptr)
            return;

        root2->data = root->data;
        mp[root] = root2;
        if (root->left != nullptr)
        {
            Node *temp = new Node(-1);
            root2->left = temp;
            cloner(root->left, root2->left);
        }
        if (root->right != nullptr)
        {
            Node *temp = new Node(-1);
            root2->right = temp;
            cloner(root->right, root2->right);
        }
    }

    void randm(Node *root)
    {
        if (root == nullptr)
            return;

        mp[root]->random = mp[root->random];

        randm(root->left);
        randm(root->right);
    }

    Node *cloneTree(Node *tree)
    {
        Node *root2 = new Node(-1);
        cloner(tree, root2);
        randm(tree);
        return root2;
    }
};
