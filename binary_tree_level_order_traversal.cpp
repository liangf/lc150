#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int> > vec;
		queue<TreeNode*> que;
		if (root == NULL) return vec;

		que.push(root);
		while ( !que.empty() ) {
			vector<int> level;
			TreeNode *end = que.back();
			while ( true ) {
				TreeNode *n = que.front();
				que.pop();
				level.push_back(n->val);

				if (n->left) que.push(n->left);
				if (n->right) que.push(n->right);
				if (n == end) break;
			}
			vec.push_back(level);
		}
		return vec;
	}
};


int main() 
{
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	Solution s;
	vector<vector<int> > vec = s.levelOrder(root);
	for (int i=0; i<vec.size(); i++) {
		for (int j=0; j<vec[i].size(); j++) {
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
}
