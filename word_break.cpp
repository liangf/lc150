#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		bool b[s.length()+1];
		s = "^" + s;
		b[0] = true;
		for (int i=1; i<=s.length(); i++) {
			for (int k=0; k<i; k++) {
				b[i] = b[k] && dict.find(s.substr(k+1, i-k))!=dict.end();
				if (b[i]) break;
			}	
		}
		return b[s.length()-1];
	}
};


int main()
{
	unordered_set<string> dict = {"aaaa", "aaa"};
	string s = "aaaaaaa";
	//s.erase(0, 4);
	//cout << s << endl;
	Solution S;
	cout << S.wordBreak(s, dict) << endl;
}
