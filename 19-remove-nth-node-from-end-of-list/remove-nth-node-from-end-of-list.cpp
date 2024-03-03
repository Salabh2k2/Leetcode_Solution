/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* fast = head;
        while(n)
        {
            fast  = fast->next;
            n--;
        }
        if(!fast) return head->next;
        while(fast->next)
        {
            fast = fast->next;
            temp = temp->next;
        }
        temp->next = temp->next->next;

        return head;
    }
};