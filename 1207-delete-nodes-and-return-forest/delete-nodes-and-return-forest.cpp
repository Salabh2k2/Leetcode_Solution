#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr, right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* rec(TreeNode* root, set<int>& st, vector<TreeNode*>& result) {
        if (!root) return nullptr; // base case
        
        root->left = rec(root->left, st, result);
        root->right = rec(root->right, st, result);
        
        if (st.find(root->val) != st.end()) {
            if (root->left) result.push_back(root->left);
            if (root->right) result.push_back(root->right);
            delete root;
            return nullptr;
        }
        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        set<int> st(to_delete.begin(), to_delete.end());
        
        root = rec(root, st, result);
        
        if (root && st.find(root->val) == st.end()) {
            result.push_back(root);
        }
        
        return result;
    }
};
