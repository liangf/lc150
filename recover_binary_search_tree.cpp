#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void recoverTree(TreeNode *root) {
		TreeNode *old = NULL, *n1 = NULL, *n2 = NULL;
		in_order(root, old, n1, n2);
		//cout << n1->val << " " << n2->val << endl;
		if (n1 && n2) swap(n1->val, n2->val);
	}
	void in_order(TreeNode *root,  TreeNode *&old, 
					TreeNode *&n1, TreeNode *&n2) {
		if (root == NULL) return;
		
		in_order(root->left, old, n1, n2);	
		if (old && old->val>root->val) {
			if (n1 == NULL) n1 = old;
			n2 = root;
		}
		old = root;
		in_order(root->right, old, n1, n2);
	}
	void print(TreeNode *root) {
		if (root == NULL) return;
		print(root->left);
		cout << root->val << endl;
		print(root->right);
	}
};

int main()
{

	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(2);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(4);
/*
	TreeNode *root = new TreeNode(0);
	root->left = new TreeNode(1);
*/	
	Solution s;
	s.recoverTree(root);
	s.print(root);
}
