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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<TreeNode*> v1 ;
        vector<TreeNode*> v2;
        vector<vector<int> > res ;
        if(root==NULL) return res ;
        v1.push_back(root);
        bool flag = true ;
        while(!v1.empty()){
            res.push_back(num(v1,flag));
            flag = !flag;
            for(int i = 0 ; i < v1.size() ; i++){
                TreeNode* t = v1[i];
                if(t->left) v2.push_back(t->left);
                if(t->right) v2.push_back(t->right);
            }
            v1.clear();
            v1 = v2 ;
            v2.clear();
        }
        return res ;
    }
    vector<int> num(vector<TreeNode*> &v ,bool flag ){
        vector<int> res ;
        for(int i = 0 ; i < v.size() ; i++){
            if(flag)
                res.push_back(v[i]->val);
            else
                res.push_back(v[v.size()-1-i]->val);
        }
        return res;
    }
};
