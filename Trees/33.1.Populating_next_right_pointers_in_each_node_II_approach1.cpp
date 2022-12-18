/*
// Definition for a Node.
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

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;

        if(root == nullptr) return nullptr;
        q.push(root);

        while(!q.empty())
        {
            vector<Node*> order;
            int n = q.size();
            for(int i = 0;i<n;i++)
            {

                Node* temp = q.front();
                q.pop();

                if(temp->left)
                {
                    q.push(temp->left);
                }

                if(temp->right)
                {
                    q.push(temp->right);
                }
                order.push_back(temp);
            }
            for(int i = 0; i<order.size(); i++)
            {
                if(i+1<order.size())
                {
                    order[i]->next = order[i+1];
                }
                else{
                    order[i]->next = nullptr;
                }
            }
        }
        return root;
    }
};