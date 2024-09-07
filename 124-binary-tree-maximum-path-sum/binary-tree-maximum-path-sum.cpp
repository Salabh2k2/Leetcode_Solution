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
    int rec(TreeNode* root, int &ans)
    {
        if(root==NULL) return 0;
        
        int leftval = max(0,rec(root->left,ans));
        
        int rightval = max(0,rec(root->right,ans));
        ans = max(ans,root->val+leftval+rightval);
        return root->val+max(leftval,rightval);
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
       int k = rec(root,ans);
       return ans;
        
    }
};