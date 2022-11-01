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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        unordered_map<ListNode *, int> mp;

        while (headA != nullptr)
        {
            mp[headA]++;
            headA = headA->next;
        }
        while (headB != nullptr)
        {
            mp[headB]++;
            if (mp[headB] == 2)
                return headB;

            headB = headB->next;
        }
        return nullptr;
    }
};