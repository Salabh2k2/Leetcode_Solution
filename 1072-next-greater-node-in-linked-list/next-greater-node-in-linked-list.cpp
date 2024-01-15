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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> v;
        stack<int> st;
        while(head!=NULL){
            v.push_back(head->val);
            head=head->next;
        }
        vector<int> ans(v.size(),0);
        for(int i=0;i<v.size();i++){
            while(!st.empty() and v[st.top()]<v[i]){
                ans[st.top()]=v[i];
                st.pop();
            }
            st.push(i);
        }   
    return ans;        
    }
};