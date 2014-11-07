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
	ListNode *partition(ListNode *head, int x) {
		ListNode *head2 = new ListNode(INT_MAX);
		head2->next = head;
		// find the 1st elem >= x
		ListNode *p = head;
		ListNode *pre = head2;
		while (p != NULL) {
			if (p->val >= x) break;
			pre = p;
			p = p->next;
		}
		if (p == NULL) return head;
		// [p->next, end], insert the <x befor p
		ListNode *q = p;
		while (q->next != NULL) {
			if (q->next->val < x) {
				ListNode *tmp = q->next;
				q->next = tmp->next;
				pre->next = tmp;
				tmp->next = p;
				pre = pre->next;
			}
			else q = q->next;			
		}	
		return head2->next;
	}
};

int main()
{/*
	ListNode *head= new ListNode(1);
	ListNode *n2 = new ListNode(4);
	ListNode *n3 = new ListNode(3);
	ListNode *n4 = new ListNode(2);
	ListNode *n5 = new ListNode(5);
	ListNode *n6 = new ListNode(2);
	head->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;*/

	ListNode *head = new ListNode(2);
	head->next = new ListNode(1);

	Solution s;
	head = s.partition(head, 1);
	while (head) {
		cout << head->val << endl;
		head = head->next;
	}
}
