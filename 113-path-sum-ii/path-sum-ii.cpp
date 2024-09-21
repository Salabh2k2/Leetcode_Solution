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
    vector<vector<int>>ans;
    void dfs(TreeNode* root, int target, vector<int>temp, int sum)
    {
        if(!root) return;
        sum+=root->val;
        if(root->left==NULL && root->right==NULL)
        {
            if(sum==target)
            {
                temp.push_back(root->val);
                ans.push_back(temp);
                return;
            }
        }
        temp.push_back(root->val);
        dfs(root->left,target,temp,sum);
        dfs(root->right,target,temp,sum);
        temp.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        dfs(root,targetSum,temp,0);
        return ans;
    }
};