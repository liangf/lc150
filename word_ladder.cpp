#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

struct Node {
	string word;
	int level;
	Node(string w, int l) : word(w), level(l) {}
};

class Solution {
public:
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		if (dict.size() <= 0) return 0;
		dict.insert(start); 
		dict.insert(end); 
		queue<Node> q;
		q.push(Node(start, 1));
		dict.erase(start);
		while ( !q.empty() ) {
			Node old = q.front();
			q.pop();
			//cout << old.level  << " " << old.word << endl;
			if (old.word == end) return old.level;
			for (int i=0; i<old.word.length(); i++) {
				string s = old.word;
				for (char c='a'; c<='z'; c++) {
					s[i] = c;
					if (dict.find(s) != dict.end()) {
						q.push(Node(s, old.level+1));
						dict.erase(s);
					}
				}
			}
		}	
		return 0;
	}
};

int main()
{
	string start = "hit", end = "cog";
	unordered_set<string> dict = {"hot", "dot", "dog", "lot", "log"};

	Solution s;
	cout << s.ladderLength(start, end, dict) << endl;
}
