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
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		return insert(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
	}
	TreeNode *insert(vector<int> &inorder, vector<int> &postorder,
					int instart, int inend, int postart, int poend) {
		if (instart > inend) return NULL;

		TreeNode *root = new TreeNode(postorder[poend]);
		int mid = getIndex(inorder, instart, inend, postorder[poend]);	
		root->left = insert(inorder, postorder, instart, mid-1, postart, postart+mid-instart-1);
		root->right = insert(inorder, postorder, mid+1, inend, postart+mid-instart, poend-1);
		return root;
	}
	int getIndex(vector<int> &inorder, int start, int end, int key) {
		for (int i=start; i<=end; i++) {
			if (key == inorder[i]) return i;
		}
		return -1;
	}
	void pre_order(TreeNode *root) {
		if (root == NULL) return;
		cout << root->val << " ";
		pre_order(root->left);
		pre_order(root->right);
	}
};


int main()
{
	vector<int> inorder;
	vector<int> postorder;

	inorder.push_back(1);
	inorder.push_back(2);
	inorder.push_back(3);
	inorder.push_back(4);
	inorder.push_back(5);
	inorder.push_back(6);
	
	postorder.push_back(1);
	postorder.push_back(3);
	postorder.push_back(2);
	postorder.push_back(6);
	postorder.push_back(5);
	postorder.push_back(4);

	Solution s;
	TreeNode *root = s.buildTree(inorder, postorder);
	s.pre_order(root);
	cout << endl;	
}
