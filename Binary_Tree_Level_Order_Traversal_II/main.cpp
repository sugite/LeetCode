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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<TreeNode*> v1 ;
        vector<TreeNode*> v2;
        vector<vector<int> > res ;
        if(root==NULL) return res ;
        v1.push_back(root);
        while(!v1.empty()){
            res.push_back(num(v1));
            for(int i = 0 ; i < v1.size() ; i++){
                TreeNode* t = v1[i];
                if(t->left) v2.push_back(t->left);
                if(t->right) v2.push_back(t->right);
            }
            v1.clear();
            v1 = v2 ;
            v2.clear();
        }
        for(int i = 0 ; i < res.size()/2 ; i++){
            vector<int> temp(res[i]);
            res[i] = res[res.size()-1-i];
            res[res.size()-1-i] = temp ;
        }
        return res ;
    }
    vector<int> num(vector<TreeNode*> &v){
        vector<int> res ;
        for(int i = 0 ; i < v.size() ; i++){
            res.push_back(v[i]->val);
        }
        return res;
    }
};
