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
    bool isBalanced(TreeNode *root) {
            int x = 0;
            return isBalancedAux(root, x);
        }

    private:
        bool isBalancedAux(TreeNode *root, int& depth) {
            if (root == NULL) { depth = 0; return true; }

            if (root->left == NULL && root->right == NULL) {
                depth = 1;
                return true;
            }

            int left_depth = 0, right_depth = 0;
            if (isBalancedAux(root->left, left_depth) && 
                isBalancedAux(root->right, right_depth)) {
                int distance = left_depth - right_depth;
                if (-1 <= distance && distance <= 1) {
                    depth = max(left_depth, right_depth) + 1;
                    return true;
                }
            }

            depth = max(left_depth, right_depth) + 1;
            return false;
        }
};
