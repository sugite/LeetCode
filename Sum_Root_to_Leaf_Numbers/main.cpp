/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        if(root==NULL) return 0;
        return myFunc(root , root->val);
    }
    
    int myFunc(TreeNode *root, int val){
        if(root->left==NULL && root->right==NULL) return val ;
        int left = root->left ? myFunc(root->left,val*10+root->left->val) : 0;
        int right = root->right ? myFunc(root->right,val*10+root->right->val) : 0;
        return left+right;
    }
};
