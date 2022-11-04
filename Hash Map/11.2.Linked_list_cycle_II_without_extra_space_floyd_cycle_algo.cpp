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

        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        if (!(fast && fast->next))
            return nullptr;
        while (head != slow)
        {
            head = head->next;
            slow = slow->next;
        }
        return head;
    }
};