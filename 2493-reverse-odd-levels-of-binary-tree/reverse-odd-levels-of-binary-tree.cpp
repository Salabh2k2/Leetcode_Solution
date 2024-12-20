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

    void solve(TreeNode* L, TreeNode* R, int level)
    {
        if(L==NULL) return;
        solve(L->left, R->right,level+1);
        solve(L->right,R->left,level+1);
        if(level%2!=0)
        {
            swap(L->val, R->val);
        }
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return NULL;
        solve(root->left,root->right,1);
        return root;
    }
};