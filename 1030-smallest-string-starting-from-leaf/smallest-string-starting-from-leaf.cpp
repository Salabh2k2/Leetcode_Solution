class Solution {
public:
    void dfs(TreeNode* root, vector<string>& paths, string current_path) {
        if (!root) return;
        
        current_path += char('a' + root->val);
        
        if (!root->left && !root->right) {
            reverse(current_path.begin(), current_path.end());
            paths.push_back(current_path);
            return;
        }
        
        dfs(root->left, paths, current_path);
        dfs(root->right, paths, current_path);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        if (!root) return "";
        
        vector<string> paths;
        dfs(root, paths, "");
        
        return *min_element(paths.begin(), paths.end());
    }
};
