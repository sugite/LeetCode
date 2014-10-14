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
    TreeNode *first = NULL ;
    TreeNode *second = NULL;
    TreeNode *pre = new TreeNode(-100000);
    void recoverTree(TreeNode *root) {
        inOrder(root);
        int temp = first->val;
        first->val = second->val ; 
        second->val = temp ;
    }
    
    void inOrder(TreeNode *root){
        if(root==NULL) return ;
        inOrder(root->left);
        if(first==NULL && pre->val>root->val)
            first = pre;
        if(first && pre->val>root->val)
            second = root;
        pre = root;
        inOrder(root->right);
    }
};
