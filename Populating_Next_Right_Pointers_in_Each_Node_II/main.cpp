/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return ;
        vector<TreeLinkNode *> v1,v2;
        v1.push_back(root);
        while(!v1.empty() || !v2.empty()){
            if(v2.empty()){
                for(int i = 0 ; i < v1.size() ; ++i){
                    v1[i]->next = i+1==v1.size() ? NULL : v1[i+1];
                    if(v1[i]->left) v2.push_back(v1[i]->left);
                    if(v1[i]->right) v2.push_back(v1[i]->right);
                }
                v1.clear();
            }else{
                for(int i = 0 ; i < v2.size() ; ++i){
                    v2[i]->next = i+1==v2.size() ? NULL : v2[i+1];
                    if(v2[i]->left) v1.push_back(v2[i]->left);
                    if(v2[i]->right) v1.push_back(v2[i]->right);
                }
                v2.clear();
            }
        }
    }
};