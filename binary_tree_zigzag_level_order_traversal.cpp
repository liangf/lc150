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
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<int> result;
		vector<vector<int> > solution;
		vector<TreeNode *> vec;
		if (root == NULL) return solution;
		
		vec.push_back(root);
		result.push_back(root->val);
		solution.push_back(result);
		int k = 1;
		while (1) {
			result.clear();
			vector<TreeNode *> tmp;
			if (k%2 == 0) {
				for (int i=vec.size()-1; i>=0; i--) {
					if (vec[i]->left) {
						tmp.push_back(vec[i]->left);
						result.push_back(vec[i]->left->val);
					}
					if (vec[i]->right) {
						tmp.push_back(vec[i]->right);
						result.push_back(vec[i]->right->val);
					}
				}
			}
			else {
				for (int i=vec.size()-1; i>=0; i--) {
					if (vec[i]->right) {
						tmp.push_back(vec[i]->right);
						result.push_back(vec[i]->right->val);
					}
					if (vec[i]->left) {
						tmp.push_back(vec[i]->left);
						result.push_back(vec[i]->left->val);
					}
				}
			}
			vec = tmp;	
			if (vec.size() == 0) break;
			solution.push_back(result);
			k++;
		}
		return solution;
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
	vector<vector<int> > solution = s.zigzagLevelOrder(root);
	for (int i=0; i<solution.size(); i++) {
		for (int j=0; j<solution[i].size(); j++) {
			cout << solution[i][j] << " ";
		}
		cout << endl;
	}
}
