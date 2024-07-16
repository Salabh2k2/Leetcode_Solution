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
    // Function to find the LCA of two nodes given their values
    TreeNode* findLCA(TreeNode* root, int p_val, int q_val) {
        if (root == NULL || root->val == p_val || root->val == q_val) {
            return root;
        }
        TreeNode* leftLCA = findLCA(root->left, p_val, q_val);
        TreeNode* rightLCA = findLCA(root->right, p_val, q_val);
        if (leftLCA != NULL && rightLCA != NULL) {
            return root;
        }
        return (leftLCA != NULL) ? leftLCA : rightLCA;
    }

    bool dfs(TreeNode* root, int destValue, string &path) {
        if (root == NULL) return false;
        if (root->val == destValue) return true;

        path.push_back('L');
        if (dfs(root->left, destValue, path)) return true;
        path.pop_back();

        path.push_back('R');
        if (dfs(root->right, destValue, path)) return true;
        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = findLCA(root, startValue, destValue);

        string pathToStart = "";
        dfs(lca, startValue, pathToStart);
        string pathToDest = "";
        dfs(lca, destValue, pathToDest);

        // Replace the path to start with 'U'
        string result(pathToStart.size(), 'U');
        result += pathToDest;

        return result;
    }
};
