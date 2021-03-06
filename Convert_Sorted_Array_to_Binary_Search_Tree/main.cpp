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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        TreeNode *root = addValue(num,0,num.size()-1);
        return root;
    }
    TreeNode *addValue(vector<int> &num,int low,int high){
        if(low>high) return NULL;
        int mid = (low+high)/2;
        TreeNode *t = new TreeNode(num[mid]);
        t->left = addValue(num,low,mid-1);
        t->right = addValue(num,mid+1,high);
        return t;
    }
};