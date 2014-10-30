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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return treeBuild(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
    
    TreeNode *treeBuild(vector<int> &preorder,int preStart ,int preEnd, vector<int> &inorder,int inStart ,int inEnd){
        if(preStart>preEnd) return NULL;
        if(inStart>inEnd) return NULL;
        int rootVal = preorder[preStart];
        TreeNode *root = new TreeNode(rootVal);
        if(preEnd==preStart) return root ;
        int index = -1 ;
        for(int i = inStart ; i <= inEnd ; i++){
            if(inorder[i]==rootVal){
                index = i ; 
                break;
            }
        }
        root->left = treeBuild(preorder,preStart+1,preStart+index-inStart,inorder,inStart,index-1);
        root->right = treeBuild(preorder,preStart+index-inStart+1,preEnd,inorder,index+1,inEnd);
        return root;
    }
    
};
