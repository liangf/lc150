#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *sortList(ListNode *head) {
		if (head == NULL) return NULL;
		
		int count = 0;
		ListNode *p = head;
		while (p != NULL) {
			count++;
			p = p->next;
		}	
		head = sort(head, count);	
		return head;
	}

	ListNode* sort(ListNode *head, int len) {
		if (len == 1) {
			head->next = NULL;
			return head;
		}

		ListNode *left, *midnode, *right;
		left = head;
		midnode = getMiddleNode(head, len);		
		right = midnode->next;

		left = sort(left, len/2); 
		right = sort(right, len-len/2);
		head = merge(left, len/2, right, len-len/2);
		return head;
	}

	ListNode* merge(ListNode *left, int lenL, ListNode *right, int lenR) {
		ListNode *head = new ListNode(-1);
		ListNode *cur = head;
		int countL = 0, countR = 0;
		while(left && right && countL<lenL && countR<lenR) {
			if (left->val <= right->val) {
				cur->next = left;
				left = left->next;
				countL++;
			}
			else {
				cur->next = right;
				right = right->next;
				countR++;
			}
			cur = cur->next;
		}
		if (countL == lenL) cur->next = right;
		else cur->next = left; 
		cur = head->next;
		delete head;
		return cur;
	}

	ListNode* getMiddleNode(ListNode *head, int len) {
		ListNode *midnode = head;
		int count = 0;
		while (midnode != NULL) {
			count++;
			if (count == len/2) break;
			midnode = midnode->next;
		}	
		return midnode;
	}
};

int main()
{
	ListNode *head = new ListNode(3);
	head->next = new ListNode(2);
	head->next->next = new ListNode(1);

	Solution s;
	head = s.sortList(head);
	while (head) {
		cout << head->val << endl;
		head = head->next;
	}
}
