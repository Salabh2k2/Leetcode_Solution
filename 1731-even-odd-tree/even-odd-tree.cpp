
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(root == nullptr) return false;
        
        queue<TreeNode*> q;
        q.push(root);

        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            vector<int> level_values(size);

            for(int i = 0; i < size; ++i) {
                TreeNode* temp = q.front();
                q.pop();

                // Check if the value violates the conditions
                if((level % 2 == 0 && (temp->val % 2 == 0 || (i > 0 && temp->val <= level_values[i - 1]))) ||
                   (level % 2 != 0 && (temp->val % 2 != 0 || (i > 0 && temp->val >= level_values[i - 1])))) {
                    return false;
                }

                level_values[i] = temp->val;

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            // Check if the level values satisfy the conditions
            if(level % 2 == 0) {
                for(int val : level_values) {
                    if(val % 2 == 0) return false;
                }
            } else {
                for(int val : level_values) {
                    if(val % 2 != 0) return false;
                }
            }

            ++level;
        }
        
        return true;
    }
};
