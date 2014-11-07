#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		return divide(lists, 0, lists.size()-1);
	}
	ListNode* divide(vector<ListNode *> &lists, int left, int right) {
		if (left > right) return NULL;
		if (left == right)	return lists[left]; 
		int mid = (left+right)/2;
		ListNode *ln = divide(lists, left, mid);
		ListNode *rn = divide(lists, mid+1, right);
		return merge(ln, rn);
	}
	ListNode* merge(ListNode *left, ListNode *right) {
		ListNode *head = new ListNode(-1);
		ListNode *p = head;
		while (left && right) {
			if (left->val < right->val) {
				p->next = left;
				left = left->next;
			}		
			else {
				p->next = right;
				right = right->next;
			}
			p = p->next;
		}
		p->next = left!=NULL ? left : right;
		return head->next;
	}
};

int main()
{
	ListNode *l1 = new ListNode(1);
	l1->next = new ListNode(2);
	
	ListNode *l2 = new ListNode(2);
	l2->next = new ListNode(3);

	ListNode *l3 = new ListNode(4);
	
	vector<ListNode *> lists;
	//lists.push_back(l1);
	//lists.push_back(l2);
	//lists.push_back(l3);
	
	Solution s;
	l1 = s.mergeKLists(lists);
	while (l1) {
		cout << l1->val << endl;
		l1 = l1->next;
	}
}
