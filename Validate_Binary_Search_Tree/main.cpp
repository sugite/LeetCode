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
    int v = -99999;
    bool flag = true;
    bool isValidBST(TreeNode *root) {
        if(root==NULL) return true ;
        traversal(root);
        return flag;
    }
    
    void traversal(TreeNode *root){
        if(root){
            traversal(root->left);
            flag = flag && root->val>v;
            if(!flag) return ;
            v = root->val ;
            traversal(root->right);
        }
    }
};
