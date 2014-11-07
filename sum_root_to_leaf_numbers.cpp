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
	int sumNumbers(TreeNode *root) {
		int sum = 0;
		vector<int> path;
		pre_order(root, path, sum);
		return sum; 
	}
	void pre_order(TreeNode *root, vector<int> &path, int &sum) {
		if (root == NULL) {
			path.push_back(0);
			return;
		}	
		if (root->left==NULL && root->right==NULL) {
			path.push_back(root->val);
			int old_sum = sum;
			sum = 0;
			for (int i=0; i<path.size(); i++) {
				//cout << path[i] << " ";
				sum = sum*10 + path[i];
			}
			sum = sum + old_sum;
			//cout << endl;
			return;
		}	
		path.push_back(root->val);	
		pre_order(root->left, path, sum);
		path.pop_back();
		pre_order(root->right, path, sum);
		path.pop_back();
	}
};


int main() 
{
	TreeNode *root = new TreeNode(6);
	root->left = new TreeNode(4);
	root->right = new TreeNode(1);
	root->left->left = new TreeNode(6);
	root->left->left->right = new TreeNode(4);
	root->left->left->right->left = new TreeNode(2);
	root->left->left->right->left->left = new TreeNode(6);

	Solution s;
	cout << s.sumNumbers(root) << endl;
}
