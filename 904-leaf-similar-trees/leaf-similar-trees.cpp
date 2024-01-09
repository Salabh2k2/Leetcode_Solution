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
   
    void leafseq (TreeNode* root, vector<int>& ans)
    {
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(root->val);
        }
        if(root->left) leafseq(root->left, ans);
        if(root->right) leafseq(root->right, ans);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
         vector<int>ans;
         vector<int>ans2;
        leafseq(root1,ans);
        leafseq(root2,ans2);
        if(ans.size()!=ans2.size()) return false;
        else{
            for(int i = 0;i<ans.size();i++)
            {
                if(ans[i] !=ans2[i]) return false;
            }
        }
        return true;


    }
};