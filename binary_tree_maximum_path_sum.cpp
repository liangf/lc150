#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxPathSum(TreeNode *root) {
		int max_path_sum = INT_MIN;
		int a = maxOnePathSum(root, max_path_sum);
		return max_path_sum;
	}
	int maxOnePathSum(TreeNode *root, int &max_path_sum) {
		if (root == NULL) return 0;
		int left = maxOnePathSum(root->left, max_path_sum);
		int right = maxOnePathSum(root->right, max_path_sum);
		int single = max(max(left+root->val, right+root->val), root->val);
		max_path_sum = max(max(left+root->val+right, max_path_sum), single);
		return single;
	}
};

int main()
{
/*	TreeNode *root = new TreeNode(-2);
	root->left = new TreeNode(3);
	root->right = new TreeNode(1);
*/
	TreeNode *root = new TreeNode(2);
	root->left = new TreeNode(-1);

	Solution s;
	cout << s.maxPathSum(root) << endl;
}
