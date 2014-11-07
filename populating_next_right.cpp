#include <iostream>
#include <stack>
#include <queue>
using namespace std;


struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root == NULL) return;
		
		queue<TreeLinkNode*> que;
		que.push(root);
		while ( !que.empty() )	{
			queue<TreeLinkNode*> que2;
			TreeLinkNode *head = que.front();
			que.pop();
			if (head->left) que2.push(head->left);
			if (head->right) que2.push(head->right);
//cout << head->val << "->";
			while ( !que.empty() ) {
				TreeLinkNode *n = que.front();
				n = que.front();
				que.pop();
				if (n->left) que2.push(n->left);
				if (n->right) que2.push(n->right);
				head->next = n;
				head = head->next;
//cout << head->val << "->";
			}
			que = que2;
			head->next = NULL;
//cout << "NULL" << endl;
		}
	}
};

int main()
{
	TreeLinkNode *root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	root->left->left = new TreeLinkNode(4);
	root->left->right = new TreeLinkNode(5);
	root->right->left = new TreeLinkNode(6);
	root->right->right = new TreeLinkNode(7);

	Solution s;
	s.connect(root);
}
