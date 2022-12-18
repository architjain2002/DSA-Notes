/*
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {

        Node *root2 = root;
        while (root2 != nullptr)
        {
            Node *temp = new Node();
            Node *curr = temp;

            while (root2 != nullptr)
            {
                if (root2->left)
                {
                    curr->next = root2->left;
                    curr = curr->next;
                }
                if (root2->right)
                {
                    curr->next = root2->right;
                    curr = curr->next;
                }
                root2 = root2->next;
            }
            root2 = temp->next;
        }
        return root;
    }
};