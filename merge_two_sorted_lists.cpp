#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode *head;
		ListNode *p;

		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;

		if (l1->val <= l2->val) {
			head = new ListNode(l1->val);
			l1 = l1->next;
		}
		else {
			head = new ListNode(l2->val);
			l2 = l2->next;
		}
		p = head;		
		
		while (l1!=NULL && l2!=NULL) {
			if (l1->val <= l2->val) {
				p->next = new ListNode(l1->val);
				l1 = l1->next;
			}
			else {
				p->next = new ListNode(l2->val);
				l2 = l2->next;
			}
			p = p->next;
		}
		while (l1 !=NULL) {
			p->next = new ListNode(l1->val);
			l1 = l1->next;
			p = p->next;
		}	
		while (l2 !=NULL) {
			p->next = new ListNode(l2->val);
			l2 = l2->next;
			p = p->next;
		}
		return head;	
	}
};


int main()
{
	ListNode *l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(3);

	ListNode *l2 = new ListNode(2);
	l2->next = new ListNode(3);
 	l2->next->next = new ListNode(4);

	Solution s;
	ListNode *head = s.mergeTwoLists(l1, l2);
	
	while (head) {
		cout << head->val << endl;
		head = head->next;
	}
}
