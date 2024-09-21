class Solution {
public:
    bool ans = false;
    
    void dfs(TreeNode* root, int target, int sum) {
        if(!root) return;  // If the node is null, just return.
        
        sum += root->val;  // Add the current node value to the sum.
        
        // If it's a leaf node (no left or right children) and the sum matches the target, update ans.
        if(!root->left && !root->right) {
            if(sum == target) {
                ans = true;
            }
            return;
        }
        
        // Continue to traverse the left and right subtrees.
        dfs(root->left, target, sum);
        dfs(root->right, target, sum);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        dfs(root, targetSum, 0);
        return ans;
    }
};
