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
    ListNode* doubleIt(ListNode* head) 
    {
        ListNode* temp = head;
        //ListNode* newhead = reverse(temp);
        stack<ListNode*>st;
        if(head==NULL) return head;
        while(temp)
        {
            st.push(temp);
            temp = temp->next;
        }
        int carry = 0;
        while(!st.empty())
        {
            ListNode* curr = st.top();
            st.pop();
            int k =  curr->val*2+carry;
            int v = k%10;
            curr->val = v;
            carry = k/10;
        }
        if(carry >0)
        {
            ListNode* newnode = new ListNode(carry);
            newnode->next = head;
            head = newnode;
        }
        return head;

    }
};