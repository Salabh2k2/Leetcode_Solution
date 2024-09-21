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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(ListNode* head)
    {
        if(!head) return NULL;
         if (head->next == NULL) return new TreeNode(head->val);
        ListNode* prev = NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next)
        {   
            prev= slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        prev->next = NULL;
        TreeNode* root = new TreeNode(slow->val);
        root->left = dfs(head);
        root->right = dfs(slow->next);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return dfs(head);
    }
};