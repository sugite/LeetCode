#include<iostream>
#include<vector>
#include<list>
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
	vector<int> postorderTraversal(TreeNode *root){
		if(root==NULL) return rec;
		stack.push_back(root);
		while(!stack.empty()){
			TreeNode *temp = stack.back();
			rec.push_back(temp->val);
			stack.pop_back();
			if(temp->left)
				stack.push_back(temp->left);
			if(temp->right)
				stack.push_back(temp->right);
		}
		for(size_t i = 0 ; i < rec.size()/2 ; ++i){
			int t = rec[i];
			rec[i] = rec[rec.size()-i-1];
			rec[rec.size()-1-i] = t;
		}
		return rec;
	}
};
