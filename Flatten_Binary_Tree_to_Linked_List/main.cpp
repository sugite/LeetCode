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
    void flatten(TreeNode *root) {
        if(root==NULL || (root->left==NULL&&root->right==NULL))
            return ;
        if(root->left&&root->right==NULL){
            flatten(root->left);
            root->right = root->left;
            root->left = NULL;
            return ;
        }
        if(root->right&&root->left==NULL){
            flatten(root->right);
            return ;
        }
        flatten(root->left);
        flatten(root->right);
        TreeNode *temp = root->right;
        root->right = root->left;
        root->left = NULL;
        fun(root->right,temp);
    }
    void fun(TreeNode *tn1, TreeNode *tn2){
        if(tn1->right==NULL){
            tn1->right = tn2 ;
        }else{
            fun(tn1->right,tn2);   
        }
    }
};
