class Solution {
public:
    TreeNode* dfs(vector<int> &nums, int start, int end) {
        if (start > end) return nullptr;
        
        // Calculate mid index based on start and end
        int mid = start + (end - start) / 2;
        
        // Create root with the mid element
        TreeNode* root = new TreeNode(nums[mid]);
        
        // Recursively build the left and right subtrees
        root->left = dfs(nums, start, mid - 1);
        root->right = dfs(nums, mid + 1, end);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // Call the dfs function on the entire array
        return dfs(nums, 0, nums.size() - 1);
    }
};
