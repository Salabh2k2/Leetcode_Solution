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
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;

        int lh = 1;
        int rh = 1;
        if(root->left)
        {
            lh = 1+ maxDepth(root->left);
        }
        if(root->right)
        {
            rh = 1+ maxDepth(root->right);
        }
        return max(lh,rh);
    }
};