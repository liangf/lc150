#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		if (n == 0) return head;
		int count = 0;
		ListNode *p = head;
		while (p) {
			count++;
			p = p->next;
		}	
		ListNode *head2 = new ListNode(-1);
		head2->next = head;
		p = head2;
		int count2 = -1;
		while (p) {
			count2++;
			if (count2 == count-n) break;
			p = p->next;
		}
		p->next = p->next->next;
		return head2->next;
	}
};

int main() 
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);

	Solution s;
	head = s.removeNthFromEnd(head, 0);
	while (head) {
		cout << head->val << endl;
		head = head->next;
	}
}
