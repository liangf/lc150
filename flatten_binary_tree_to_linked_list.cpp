#include <iostream>
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
	void flatten(TreeNode *root) {
		head = NULL;
		pre_order(root);
	}
	void pre_order(TreeNode *root) {
		if (root == NULL) return;
		
		TreeNode *right = root->right;
		if (head == NULL) head = root;
		else {
			head->right = root;
			head->left = NULL;
			head = head->right;
		}
		//cout << root->val << " " << head->val << endl;	
		pre_order(root->left);
		pre_order(right);
	}
private:
	TreeNode *head;		
};*/

class Solution {
public:
	void flatten(TreeNode *root) {
		TreeNode *old = NULL;
		pre_order(root, old);
	}
	void pre_order(TreeNode *root, TreeNode *&old) {
		if (root == NULL) return;

		TreeNode *left = root->left;
		TreeNode *right = root->right;	
		if (old != NULL) {
			old->right = root;
			old->left = NULL;		
		}
		old = root;
		pre_order(left, old);
		pre_order(right, old);
	}
};

/*
class Solution {
public:
	void flatten(TreeNode *root) {
		TreeNode *pre = NULL;
		help(root, pre);
	}
	void help(TreeNode *root, TreeNode *&pre) {
		if (root == NULL) return;
	
		help(root->right, pre);
		help(root->left, pre);
cout << root->val << "->";
if (pre) cout << pre->val << endl;
else cout << "NULL" << endl;

		root->right = pre;
		root->left = NULL;
		pre = root;
	}
};*/

int main()
{
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);

	Solution s;
	s.flatten(root);
	while (root) {
		cout << root->val << endl;
		root = root->right;
	}
}
