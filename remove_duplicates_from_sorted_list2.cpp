#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (head == NULL) return NULL;
		ListNode *head0 = new ListNode(-1);
		head0->next = head;
		ListNode *p = head;
		ListNode *pre = head0;
		bool is_duplicated = false;
	
		while (p->next != NULL) {
			if (p->val == p->next->val) {
				is_duplicated = true;
				p->next = p->next->next; 
			}
			else {
				if ( is_duplicated ) {	
					pre->next = p->next;
					p = pre->next;
					is_duplicated = false;
				}
				else {
					pre = p;
					p = p->next;
				}
			}
		}
		if ( is_duplicated ) pre->next = p->next;
		return head0->next;
	}
};

int main()
{
/*	ListNode *head = new ListNode(1);
	ListNode *n2 = new ListNode(1);
	ListNode *n3 = new ListNode(1);
	ListNode *n4 = new ListNode(2);
	ListNode *n5 = new ListNode(3);
	head->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;*/

/*	ListNode *head = new ListNode(1);
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(3);
	ListNode *n4 = new ListNode(3);
	ListNode *n5 = new ListNode(4);
	ListNode *n6 = new ListNode(4);
	ListNode *n7 = new ListNode(5);
	head->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;*/

	ListNode *head = new ListNode(1);
	head->next = new ListNode(1);

	Solution s;
	head = s.deleteDuplicates(head);
	while (head) {
		cout << head->val << endl;
		head = head->next;
	}
}
