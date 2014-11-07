#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *reverseKGroup(ListNode *head, int k) {
		if (head == NULL) return NULL;
		int len = 0;
		ListNode *p = head;
		while (p) {
			len++;
			p = p->next;
		}
		if (k > len) return head;

		ListNode *head2 = new ListNode(-1);
		int count = 0;
		p = head;
		head = head2;
		ListNode *end = p;
		while (p) {
			if (count%k==0 && len-count<k) break;
			count++;
			ListNode *nextp = p->next;
			p->next = head->next;
			head->next = p;
			if (count%k == 0) {
				end->next = nextp;
				head = end;
				end = end->next;
			}
			p = nextp;
		}
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
	head = s.reverseKGroup(head, 1);
	while (head) {
		cout << head->val << endl;
		head = head->next;
	}
}
