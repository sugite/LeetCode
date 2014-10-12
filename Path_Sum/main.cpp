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
    bool hasPathSum(TreeNode *root, int sum) {
        if(root==NULL) return false;
        if(root&&root->left==NULL&&root->right==NULL)
            return sum==root->val;
        if(root->left&&root->right)
            return hasPathSum(root->left,sum-root->val)|| \
                    hasPathSum(root->right,sum-root->val);
        if(root->left)
            return hasPathSum(root->left,sum-root->val);
        return hasPathSum(root->right,sum-root->val);
    }
};
