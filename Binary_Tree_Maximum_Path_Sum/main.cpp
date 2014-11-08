/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
inline int max(int a , int b){
    return a>b?a:b;
}
class Solution {
public:
    int Max = INT_MIN;
    int maxPathSum(TreeNode *root) {
        if(root==NULL) return 0;
        dfs(root);
        return Max;
    }
    
    int dfs(TreeNode *root){
        if(root==NULL) return 0;
        int value = root->val;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int tmp = max(value,max(value+left,max(value+right,value+right+left)));
        Max = Max<tmp?tmp:Max;
        return max(value,max(value+left,value+right));
    }
    
    // int maxRootSum(TreeNode *root){
    //     if(root==NULL) return 0;
    //     int max = 0 , curr = 0;
    //     stack<TreeNode *> s ;
    //     TreeNode *p = root;
    //     TreeNode *pre = NULL;
    //     while(p!=NULL || !s.empty()){
    //         while(p!=NULL){
    //             s.push(p);
    //             curr += p->val;
    //             if(curr>max) max = curr;
    //             p = p->left;
    //         }
    //         p = s.top();
    //         if(p->right && pre!=p->right){
    //             p = p->right;
    //         }else{
    //             pre = p ;
    //             curr -= s.top()->val;
    //             s.pop();
    //             p = NULL;
    //         }
    //     }
    //     return max ;
    // }
};
