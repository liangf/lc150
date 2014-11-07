#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *swapPairs(ListNode *head) {
		if (head==NULL || head->next==NULL) return head;

		ListNode *oold = NULL;
		ListNode *old = head;
		ListNode *cur = head->next;

		old->next = cur->next;
		cur->next = old;
		old = cur;
		cur = head;
		head = old;
		
		int i = 2;
		while (cur != NULL) {
			i++;
			oold = old;
			old = cur;
			cur = cur->next;
			if (cur!=NULL && i%2==0) {
				old->next = cur->next;	
				cur->next = old;
				oold->next = cur;
				ListNode *tmp = cur;
				cur = old;
				old = tmp;
			}
		}
		return head;
	}
};

int main() 
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	//head->next->next->next = new ListNode(4);

	Solution s;
	head = s.swapPairs(head);
	while (head) {
		cout << head->val << endl;
		head = head->next;
	}
}
