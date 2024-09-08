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
class BSTIterator {
private:
vector<int>inorder;
int pointer = -1;
public:
    void solve(TreeNode* root)
    {
        if(root==NULL) return;
        solve(root->left);
        inorder.push_back(root->val);
        solve(root->right);
    }
    BSTIterator(TreeNode* root) {
        TreeNode* temp = root;
        solve(root);
    }
    
    int next() {
        auto it = upper_bound(inorder.begin(),inorder.end(),pointer);
        if(it!=inorder.end())
        {
            pointer = *it;
        }
        return pointer;
    }
    
    bool hasNext() {
         auto it = upper_bound(inorder.begin(),inorder.end(),pointer);
         if(it==inorder.end()) return false;
         else return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */