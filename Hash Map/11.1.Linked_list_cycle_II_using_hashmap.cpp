/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {

        ios_base ::sync_with_stdio(false);
        cin.tie(nullptr);

        unordered_map<ListNode *, int> mp;

        ListNode *temp = head;
        while (temp != nullptr)
        {
            mp[temp]++;
            if (mp[temp] > 1)
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
};