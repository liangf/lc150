#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *head = new ListNode(-1);
		ListNode *p = head;
		int add = 0;
		while (l1 || l2) {
			int sum = (l1!=NULL?l1->val:0)+(l2!=NULL?l2->val:0) + add;
			add = sum>9 ? 1 : 0;
			sum = sum % 10;
			p->next = new ListNode(sum);
			p = p->next;
			l1 = l1!=NULL ? l1->next : NULL;
			l2 = l2!=NULL ? l2->next : NULL;
		}
		if (add > 0) p->next = new ListNode(1);
		return head->next;
	}
};


int main()
{
/*	ListNode *l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);
	
	ListNode *l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);*/

	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(9);
	l2->next = new ListNode(9);

	Solution s;
	l1 = s.addTwoNumbers(l1, l2);
	while (l1) {
		cout << l1->val << endl;
		l1 = l1->next;
	}
}
