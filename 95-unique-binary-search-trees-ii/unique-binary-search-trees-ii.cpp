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
    vector<TreeNode*>dfs(int left, int right)
    {
       vector<TreeNode*>ans;
       if(left>right){
        ans.push_back(NULL);
        return ans;
       }

       for(int i = left;i<=right;i++)
       {
           vector<TreeNode*>ltv = dfs(left,i-1);
           vector<TreeNode*>rtv = dfs(i+1,right);
            for(auto lt:ltv)
            {
                for(auto rt:rtv)
                {
                     TreeNode* root = new TreeNode(i);
           root->left = lt;
           root->right = rt;
           ans.push_back(root);
                }
            }
          
          
       }return ans;

    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*>ans = dfs(1,n);
        return ans;
        
    }
};