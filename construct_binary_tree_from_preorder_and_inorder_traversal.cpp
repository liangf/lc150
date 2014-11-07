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
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		return insert(preorder, inorder, 0, inorder.size()-1, 0);	
	}
	TreeNode* insert(vector<int> &preorder, vector<int> &inorder,
				int begin, int end, int i) {
		if (begin > end) return NULL;
		//if (begin == end) return new TreeNode(inorder[begin]);

		TreeNode *root = new TreeNode(preorder[i]);
		int mid = getIndex(inorder, begin, end, preorder[i]);	
		
		root->left = insert(preorder, inorder, begin, mid-1, i+1);
		root->right = insert(preorder, inorder, mid+1, end, i+1+mid-begin);
		return root;
	}
	int getIndex(vector<int> &vec, int begin, int end, int key) {
		for (int i=begin; i<=end; i++) {
			if (key == vec[i]) return i;	
		}
		return -1;
	}
	void in_order(TreeNode *root) {
		if (root == NULL) return;
		in_order(root->left);
		cout << root->val << " ";
		in_order(root->right);
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
	vector<int> preorder;
	vector<int> inorder;

	preorder.push_back(4);
	preorder.push_back(2);
	preorder.push_back(1);
	preorder.push_back(3);
	preorder.push_back(5);
	preorder.push_back(6);

	inorder.push_back(1);
	inorder.push_back(2);
	inorder.push_back(3);
	inorder.push_back(4);
	inorder.push_back(5);
	inorder.push_back(6);
	
	Solution s;
	TreeNode *root = s.buildTree(preorder, inorder);
	s.in_order(root);
	cout << endl;
	s.post_order(root);
	cout << endl;
}
