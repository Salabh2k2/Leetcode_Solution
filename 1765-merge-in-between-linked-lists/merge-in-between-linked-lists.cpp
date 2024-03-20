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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int count = 1; // Start counting from 1
        ListNode* temp = list1;
        while (count < a) { // Traverse to node a
            temp = temp->next;
            count++;
        }
        
        ListNode* curr = temp->next;
        temp->next = list2; // Connect the previous node to the head of list2
        
        while (b >= a) {
            curr = curr->next;
            b--;
        }
        
        while (list2->next) { 
            list2 = list2->next;
        }
        
        list2->next = curr; 
        return list1;
    }
};
