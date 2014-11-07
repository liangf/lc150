#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void reorderList(ListNode *head) {
		if (head==NULL || head->next==NULL) return;		
		ListNode *midnode = findMiddleNode(head);
		ListNode *head2 = midnode->next;
		midnode->next = NULL;
		head2 = reverse(head2);
		head = merge(head, head2);
	}
	ListNode *merge(ListNode *head, ListNode *head2) {
		ListNode *cur = head, *next = head;
		ListNode *cur2 = head2, *next2 = head2;
		while (cur && cur2) {
			next = cur->next;
			next2 = cur2->next;
			cur->next = cur2;
			cur2->next = next;
			cur = next;
			cur2 = next2;
		}

		return head;
	}
	ListNode* findMiddleNode(ListNode *head) {
		if (head==NULL || head->next==NULL) return head;
		ListNode *slow = head;
		ListNode *fast = head->next->next;

		while (fast != NULL) {
			slow = slow->next;
			if (fast->next == NULL) break;
			fast = fast->next->next;
		}	
		return slow;
	}
	ListNode* reverse(ListNode *head) {
		if (head==NULL || head->next==NULL) return head;
		ListNode *last = reverse(head->next);
		ListNode *old = head->next;
		old->next = head;
		head->next = NULL;
		return last;
	}
	void print(ListNode *head) {
		ListNode *p = head;
		while (p) {
			cout << p->val << " ";
			p = p->next;
		}
		cout << endl;
	}
};

int main()
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);

	Solution s;
	//head = s.reverse(head);
	s.reorderList(head);
	while (head) {
		cout << head->val << endl;
		head = head->next;
	}

}
