#include <iostream>
#include <unordered_map>
using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		unordered_map<RandomListNode *, RandomListNode *> umap;
		RandomListNode *newhead = new RandomListNode(-1);
		RandomListNode *oldn = head;
		RandomListNode *newn = newhead;

		while (oldn != NULL) {
			RandomListNode *p = new RandomListNode(oldn->label);	
			newn->next = p;
			umap[oldn] = p;
			oldn = oldn->next;
			newn = newn->next;
		} 	
		oldn = head;
		newn = newhead->next;
		while (oldn != NULL) {
			if (oldn->random != NULL) newn->random = umap[oldn->random];
			oldn = oldn->next;
			newn = newn->next;
		}
		return newhead->next;
	}
};

int main()
{
	RandomListNode *head = new RandomListNode(1);
	head->next = new RandomListNode(2);
	head->next->next = new RandomListNode(3);
	head->next->next->next = new RandomListNode(4);
	head->random = head->next->next;
	head->next->next->next->random = head->next;
	
	Solution s;
	RandomListNode *head2 = s.copyRandomList(head);	
	while (head2) {
		cout << head2->label << endl;
		if (head2->random) cout << "random: " << head2->random->label << endl;
		head2= head2->next;
	}
}
