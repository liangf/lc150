#include <iostream>
#include <climits>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *insertionSortList(ListNode *head) {
		if (head==NULL || head->next==NULL) return head;

		ListNode *root = new ListNode(-INT_MAX);
		root->next = head;
		ListNode *old = head;
		ListNode *cur = head->next;

		while (cur != NULL) {
			if (cur->val < old->val) {
				ListNode *p = root;
				while (p != old) {
					if (cur->val < p->next->val) break;
					p = p->next;
				}
				old->next = cur->next;
				cur->next = p->next;
				p->next = cur;
				cur = old->next;
			}
			else {
				old = cur;
				cur = cur->next;
			}
		}
		head = root->next;
		delete root;
		return head;
	}
};

int main()
{
	ListNode *head = new ListNode(3);
	head->next = new ListNode(2);
	head->next->next = new ListNode(4);
	head->next->next->next = new ListNode(2);
	
	Solution s;
	head = s.insertionSortList(head);
	while (head) {
		cout << head->val << endl;
		head = head->next;
	}
}
