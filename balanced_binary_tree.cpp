#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxHeight(TreeNode *root) {
		if (root == NULL) return 0;
		if (root->left==NULL && root->right==NULL) return 1;
		
		return max(maxHeight(root->left), maxHeight(root->right)) + 1;
	}
	bool isBalanced(TreeNode *root) {
		int b_left = getBalance(root->left);
		int b_right = getBalance(root->right);
		if ( abs(b_left-b_right) <=1 )	return true;
		else return false;
	}
};

int main()
{

}
