#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<TreeNode *> generateTrees(int n) {
		return insert(1, n);
	}
/*
	TreeNode* insert(int start, int end) {
		if (start > end) return NULL;

		for (int i=start; i<=end; i++) {
			TreeNode *root = new TreeNode(i);
			root->left = insert(start, i-1);
			root->right = insert(i+1, end);
			return root;
		}
	}
*/
	void insert(TreeNode *&root, int start, int end) {
		if (start > end) {
			root = NULL;
			return;
		}
		for (int i=start; i<=end; i++) {
			root = new TreeNode(i);
			insert(root->left, start, i-1);
			insert(root->right, i+1, end);
			return;
		}
	}
	vector<TreeNode*> insert(int start, int end) {
		vector<TreeNode*> subtree;
		if (start > end) {
			subtree.push_back(NULL);
			return subtree;
		}
		for (int k=start; k<=end; k++) {
			vector<TreeNode*> left = insert(start, k-1);
			vector<TreeNode*> right = insert(k+1, end);
			for (int i=0; i<left.size(); i++) {
				for (int j=0; j<right.size(); j++) {
					TreeNode *root = new TreeNode(k);
					root->left = left[i];
					root->right = right[j];
					subtree.push_back(root);
				}
			}
		}
		return subtree;
	}
	void pre_order(TreeNode *root) {
		if (root == NULL) return;
		cout << root->val << " ";
		pre_order(root->left);
		pre_order(root->right);
	}
	void post_order(TreeNode *root) {
		if (root == NULL) return;
		post_order(root->left);
		post_order(root->right);
		cout << root->val << " ";
	}
};


int main()
{
	int n = 3;
	Solution s;
	//s.pre_order(root); cout << endl;
	//s.post_order(root); cout << endl;
	vector<TreeNode*> sol = s.generateTrees(3);
	for (int i=0; i<sol.size(); i++) {
		s.pre_order(sol[i]); 
		cout << endl;
	}
}
