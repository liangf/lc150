#include <iostream>
#include <stack>
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
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> vec;
		TreeNode *old_left;
		TreeNode *old_right;		

		if (root == NULL) return vec;
	
		stack<TreeNode*> stk;	
		stk.push(root);
		while ( !stk.empty() ) {
			TreeNode *n = stk.top();
			if (n->left && old_left!=n->left) {
				stk.push(n->left);
			}
			else if (n->right && old_right!=n->right) {
				stk.push(n->right);
			}
			else {
				stk.pop();
				vec.push_back(n->val);
		 		if ( !stk.empty() ) {
					if ( n==stk.top()->left ) old_left = n;
					if ( n==stk.top()->right ) old_right = n;
				}
			}			
		} 	
		return vec;
	}

};


int main() 
{
	TreeNode *root = new TreeNode(2);
 	root->left = new TreeNode(4);
	root->right = new TreeNode(1);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(3);
	
	Solution s;
	vector<int> vec = s.postorderTraversal(root);
	for (int i=0; i<vec.size(); i++) cout << vec[i] << endl;
}
