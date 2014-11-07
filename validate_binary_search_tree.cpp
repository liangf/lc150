#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
class Solution {
public:
	bool isValidBST(TreeNode *root) {
		int old = INT_MIN;
		return in_order(root, old);
	}
	bool in_order(TreeNode *root, int& old) {
		if (root == NULL) return true;
		if( !in_order(root->left, old) ) return false;
		//cout << old << " " << root->val << endl;
		if (old >= root->val) return false;
		old = root->val;
		if ( !in_order(root->right, old) ) return false;
		return true;
	}
};*/

class Solution {
public:
	bool isValidBST(TreeNode *root) {
		int minval = INT_MIN, maxval = INT_MAX;
		return isValidBST(root, minval, maxval);
	}
	bool isValidBST(TreeNode *root, int minval, int maxval) {
		if (root == NULL) return true;	
		if (root->val<= minval || root->val>=maxval) return false;
		
		if ( !isValidBST(root->left, minval, root->val) ) return false;
		if ( !isValidBST(root->right, root->val, maxval) ) return false;
		return true;
	}
};


int main()
{
	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);

	Solution s;
	cout << s.isValidBST(root) << endl;
}
