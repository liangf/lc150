#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void copy(ListNode *head)
{
	cout << head << endl;
	//ListNode *n = new ListNode(2);
	//head->next = n;
	head = new ListNode(333);
}

ListNode *test()
{
	return new ListNode(123);
}

int main() 
{
	ListNode *head = new ListNode(1);
cout << head << endl;
	copy(head);
	//head = test();
	while (head) {
		cout << head->val << endl;
		head = head->next;
	}
}
