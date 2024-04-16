#include <queue>
#include <utility>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */


class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        
        while (!q.empty()) {
            TreeNode* curr = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if (level == depth - 1) {
                TreeNode* leftChild = new TreeNode(val);
                TreeNode* rightChild = new TreeNode(val);
                if (curr->left) {
                    leftChild->left = curr->left;
                }
                if (curr->right) {
                    rightChild->right = curr->right;
                }
                curr->left = leftChild;
                curr->right = rightChild;
            } else {
                if (curr->left) {
                    q.push({curr->left, level + 1});
                }
                if (curr->right) {
                    q.push({curr->right, level + 1});
                }
            }
        }
        
        return root;
    }
};
