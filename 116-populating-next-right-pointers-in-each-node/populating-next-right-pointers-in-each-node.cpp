//Upvote and Comment 

class Solution {
public:
Node* connect(Node* root) {
    //base case
    if(root == NULL) return NULL;
    if(root->left != NULL) root->left->next = root->right;
    if(root->right != NULL && root->next != NULL) root->right->next = root->next->left;
    connect(root->left);
    connect(root->right);
    return root;
   }
};