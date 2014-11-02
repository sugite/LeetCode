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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res;
        vector<int> record;
        helper(root, sum, record, res);
        return res;
    }

    void helper(TreeNode* root, int sum, vector<int> record, vector<vector<int> > & res){
        if(root==NULL) return;
        record.push_back(root->val);
        if(sum == root->val && root->left==NULL && root->right==NULL){
              res.push_back(record);
              return;
        }
        helper(root->left, sum-root->val,record,res);
        helper(root->right,sum-root->val,record,res);
    }
};
