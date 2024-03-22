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
    bool isPalindrome(ListNode* head) {
        string st = "";
        ListNode* temp = head;
        while(temp!=nullptr)
        {
            st+=to_string(temp->val);
            temp = temp->next;
        }
        string v = st;
        reverse(v.begin(),v.end());
        return v==st;
    }
};