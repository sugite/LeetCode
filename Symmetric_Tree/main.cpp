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
    bool isSymmetric(TreeNode *root) {
        return traseval(root,root);
    }
    
    bool traseval(TreeNode *root1,TreeNode *root2){
        if(root1==NULL && root2==NULL) return true;
        if(root1==NULL^root2==NULL || root1->val!=root2->val) return false ;
        return traseval(root1->left,root2->right)&&traseval(root2->left,root1->right);
    }
};
