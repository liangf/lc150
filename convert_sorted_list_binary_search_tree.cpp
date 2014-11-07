#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *sortedListToBST(ListNode *head) {
		return insert(head);		
	}
	TreeNode* insert(ListNode *head) {
		if (head == NULL) return NULL;
		if (head->next == NULL) return new TreeNode(head->val);		

		ListNode *mid = getMiddleList(head);
		ListNode *left = head;
		ListNode *right = mid->next;
		TreeNode *root = new TreeNode(mid->val);
		//cout << "mid:" << mid->val << endl;
		root->left = insert(left);
		root->right = insert(right);
		return root;
	}
	ListNode *getMiddleList(ListNode *head) {
		if (head == NULL) return NULL;
		ListNode *slow = head;
		ListNode *fast = head;
		while (fast && fast->next) {
			//cout << "fast: " << fast->val << endl;
			fast = fast->next->next;
			if (fast==NULL || fast->next==NULL) break;
			slow = slow->next;			
		}
			//cout << "slow: " << slow->val << endl;
		ListNode *mid = slow->next;
		slow->next = NULL;
		return mid;
	}
	void pre_order(TreeNode *root) {
		if (root == NULL) return;

		cout << root->val << endl;
		pre_order(root->left);
		pre_order(root->right);
	}
};

int main()
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);

	Solution s;
	//ListNode *mid = s.getMiddleList(head);
	//cout << mid->val << endl;
	TreeNode *root = s.sortedListToBST(head);
	s.pre_order(root);	
}
