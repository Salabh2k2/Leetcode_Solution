class Solution {
public:
    vector<int> v;

    void rec(TreeNode* root, int k) {
        if (root == nullptr) {
            return;
        }

        k = k * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            v.push_back(k);
            return;
        }

        if (root->left) {
            rec(root->left, k);
        }
        if (root->right) {
            rec(root->right, k);
        }
    }

    int sumNumbers(TreeNode* root) {
        rec(root, 0);
        int sum = 0;
        for (auto it : v) {
            sum += it;
        }
        return sum;
    }
};
