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
    map<int, int> mp;

    // Helper function for inorder traversal to collect values in a vector
    void inorder(TreeNode* root, vector<int>& inor) {
        if (root == nullptr) return;
        inorder(root->left, inor);
        inor.push_back(root->val);
        inorder(root->right, inor);
    }

    // Helper function for inorder traversal to update the node values
    void inorder1(TreeNode* root) {
        if (root == nullptr) return;
        inorder1(root->left);
        root->val = mp[root->val];
        inorder1(root->right);
    }

    TreeNode* bstToGst(TreeNode* root) {
        if (root == nullptr) return nullptr;

        // Get inorder traversal of the tree
        vector<int> inor;
        inorder(root, inor);

        int n = inor.size();
        vector<int> prefix(n);
        prefix[0] = inor[0];

        // Compute the prefix sum array
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + inor[i];
        }

        // Create a map with the greater sum transformation values
        mp[inor[0]] = prefix[n - 1];
        for (int i = 1; i < n; i++) {
            mp[inor[i]] = prefix[n - 1] - prefix[i - 1];
        }

        // Update the tree node values
        inorder1(root);

        return root;
    }
};
