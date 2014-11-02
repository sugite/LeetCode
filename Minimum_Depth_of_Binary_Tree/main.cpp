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
    int minDepth(TreeNode *root) {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 1;
        int left = root->left ? minDepth(root->left) : 99999 ;
        int right = root->right ? minDepth(root->right) : 99999 ;
        return 1+min(left,right);
    }
};
