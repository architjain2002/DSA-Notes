// This function should return head to the DLL
class Solution
{
public:
    // Function to convert binary tree to doubly linked list and return it.
    Node *bToDLL(Node *root)
    {
        stack<Node *> st;
        Node *node;
        Node *head = node;
        while (true)
        {
            if (root != nullptr)
            {
                st.push(root);
                root = root->left;
            }
            else
            {
                if (st.empty() == true)
                    return head;

                root = st.top();
                st.pop();

                if (node == nullptr)
                {
                    node = root;
                    head = node;
                    node->left = nullptr;
                }
                else
                {
                    // cout << node->data;
                    node->right = root;
                    root->left = node;
                    node = node->right;
                }
                root = root->right;
            }
        }
    }
};