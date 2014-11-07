#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode (int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *rotateRight(ListNode *head, int k) {
		if (head == NULL) return NULL;
		int len = 1, count = 0;
		
		ListNode *p = head;
		while (p->next) {
			p = p->next;
			len++;
		}
		p->next = head;
		k = len - k%len;
		while (count < k) {
			p = p->next;
			count++;
		}
		head = p->next;
		p->next = NULL;
		return head;
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
	head = s.rotateRight(head, 0);
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}
