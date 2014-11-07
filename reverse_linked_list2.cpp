#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *reverseBetween(ListNode *head, int m, int n) {
		ListNode *head2 = new ListNode(-1);
		head2->next = head;
		ListNode *old = head2, *last = NULL;
		ListNode *p = head;
		int count = 1;
		while (p) {
			if (count == m) {
				last = p;
				p = p->next;
			}
			else if (m<count && count<=n) {
				ListNode *tmp = p->next;
				p->next = old->next;
				old->next = p;
				p = tmp;
			}
			else if (count > n) {
				break;
			}
			else {
				old = p;
				p = p->next;
			}	
			count++;
		}
		last->next = p;
		return head2->next;
	}
};

int main()
{
	ListNode *head = new ListNode(1);
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(3);
	ListNode *n4 = new ListNode(4);
	ListNode *n5 = new ListNode(5);
	head->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	Solution s;
	head = s.reverseBetween(head, 1, 1);
	while (head) {
		cout << head->val << endl;
		head = head->next;
	}
}
