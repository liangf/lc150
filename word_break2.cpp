#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		vector<string> result;
		vector<string> solution;
		if ( !canwordBreak(s, dict) ) return solution;
		dfs(s, dict, 0, result, solution);
		return solution;
	}
	void dfs(string s, unordered_set<string> &dict, int i, 
				vector<string> &result, vector<string> &solution) {
		if (i == s.length()) {
			string ss = "";
			for (int k=0; k<result.size(); k++) {
				ss += result[k] + " "; 
			}
			ss.pop_back();
			solution.push_back(ss);
			return;
		}
		for (int len=1; len<=s.length()-i; len++) {
			if (dict.find(s.substr(i, len)) != dict.end()) {
				result.push_back(s.substr(i, len));
				dfs(s, dict, i+len, result, solution);
				result.pop_back();
			}
		}
	}
	bool canwordBreak(string s, unordered_set<string> &dict) {
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
	//string s = "catsanddog";
	//unordered_set<string> dict = {"cat", "cats", "and", "sand", "dog"};
	
	string s = "aaaaaaaaaaab";
	unordered_set<string> dict = {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa"};

	Solution S;
	vector<string> sol = S.wordBreak(s, dict);
	for (int i=0; i<sol.size(); i++) {
		cout << sol[i] << endl;
	}	
}
