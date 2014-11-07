#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
  	TreeNode *left;
	TreeNode *right;
    TreeNode(int _k) { val=_k; left=NULL; right=NULL;}
};

class Solution {
public:
	bool isSameTree(TreeNode *p, TreeNode *q) {
		if (p==NULL&&q!=NULL || p!=NULL&&q==NULL) return false;
		if (p==NULL && q==NULL) return true;
		if (p->val != q->val) return false;
		return (isSameTree(p->left, q->left) &&
				isSameTree(p->right, q->right) );
	}
};


int main() {

	TreeNode *p = new TreeNode(4);
	p->right = new TreeNode(1);
    //p->left = new TreeNode(3);
    //p->left->left = new TreeNode(2);
    //p->left->right = new TreeNode(5);  


	TreeNode *q = new TreeNode(4);
    q->left = new TreeNode(1);
    //q->left->left = new TreeNode(2);
    //q->left->right = new TreeNode(5);  
	//q->right = new TreeNode(1);
    
	
	Solution s;
	cout << s.isSameTree(p, q) << endl;
	

	return 0;
}
