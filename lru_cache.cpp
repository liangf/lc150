#include <iostream>
#include <climits>
#include <unordered_map>
using namespace std;

struct Node {
	int key;
	int value;
	Node *next;
	Node *pre;
	Node(int k, int v) : key(k), value(v), next(NULL), pre(NULL) {}
};

class LRUCache {
public:
	LRUCache(int capacity) {
		size = capacity;
		head = new Node (-1, -1);
		head->next = head;
		head->pre = head;
		count = 0;
	}
	int get(int key) {
		if (umap.find(key) == umap.end()) return -1;
		Node *n = umap[key];
		remove(n);
		insert(n);
		return n->value;
	}
	void set(int key, int value) {
		if (umap.find(key) != umap.end()) {
			remove(umap[key]);
		}
		if ((count+1) > size) remove(head->pre);
		Node *n = new Node(key, value);
		insert(n);
	}
	void insert(Node *n) {
		umap[n->key] = n;
		n->next = head->next;
		head->next->pre = n;
		head->next = n;
		n->pre = head;
		count++;
	}
	void remove(Node *n) {
		umap.erase(n->key);
		n->pre->next = n->next;
		n->next->pre = n->pre;	
		count--;
	}
	void preorder() {
		Node *p = head;
		while (1) {
			cout << p->key << endl;
			p = p->pre;
			if (p == head) break;
		}
	}
	void postorder() {
		Node *p = head;
		while (1) {
			cout << p->key << endl;
			p = p->next;
			if (p == head) break;
		}
	}
private:
	unordered_map<int, Node*> umap;
	int size;
	int count;
	Node *head;
};

int main()
{
/*	LRUCache lru(4);
	cout << "test the set\n";
	for (int i=1; i<=4; i++) {
		lru.set(i, i);
	}
	lru.postorder();
	cout << "test the get\n";
	for (int i=1; i<6; i++) {
		cout << "key:" << i << " value:" << lru.get(i) << endl;
		lru.postorder();
	}*/
/*
	LRUCache lru(1);
	lru.set(2, 1);
	cout << "get:" << lru.get(2) << endl;
	lru.set(3, 2);
	cout << lru.get(2) << endl;
	cout << lru.get(3) << endl;
*/

	LRUCache lru(2);
	cout << lru.get(2) << endl;
	lru.set(2, 6);
	cout << lru.get(1) << endl;
	lru.set(1, 5);
	lru.set(1, 2);
	cout << lru.get(1) << endl;
	cout << lru.get(2) << endl;
}
