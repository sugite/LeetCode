#include<iostream>
#include<vector>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL) {}
};

class Solution{
public:
	list<TreeNode*> stack ;
	vector<int> rec;
	vector<int> preorderTraversal(TreeNode *root){
		if(root==NULL) return NULL;
		stack.push_back(root);
		while(!stack.empty()){
			TreeNode *temp = stack.back();
			rec.push_back(temp->val);
			stack.pop_back();
			if(temp->right)
				stack.push_back(temp->right);
			if(temp->left)
				stack.push_back(temp->left);
		}
		return rec;
	}
};
