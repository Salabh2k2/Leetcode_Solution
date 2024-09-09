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

struct Node{
    int sum, maxnode, minnode;
    Node(int sum, int maxnode, int minnode){
        this->sum = sum;
        this->maxnode = maxnode;
        this->minnode = minnode;
    }
};

class Solution {
public:
        Node findLargestBST(TreeNode* root, int &ans){
        if(root->left == NULL && root->right == NULL){
            ans = max(ans,root->val);
            return Node(root->val,root->val,root->val);
        } 
        if(root->left == NULL){
            Node right = findLargestBST(root->right,ans);
            if(root->val <right.minnode){
                ans = max(ans,root->val+right.sum);
                return Node(root->val+right.sum,right.maxnode,root->val);
            }
            return Node(right.sum,INT_MAX,INT_MIN);
        } 
        if(root->right == NULL){
            Node left =  findLargestBST(root->left,ans);
            if(root->val > left.maxnode){
                ans = max(ans,root->val+left.sum);
                return Node(root->val+left.sum,root->val,left.minnode);
            }
            return Node(left.sum,INT_MAX,INT_MIN);
        } 

        Node left = findLargestBST(root->left,ans);
        Node right = findLargestBST(root->right,ans);
        if(left.maxnode<root->val && root->val<right.minnode){
            ans = max(ans, left.sum+root->val+right.sum);
            return Node(left.sum + root->val + right.sum,
                        right.maxnode,
                        left.minnode);
        }
        return Node(max(left.sum,right.sum),INT_MAX,INT_MIN);
    }
    int maxSumBST(TreeNode* root) {
        if(root == NULL ) return 0;
        int ans = 0;
        findLargestBST(root,ans);     
        return ans;
    }
};