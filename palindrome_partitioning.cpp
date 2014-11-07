#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<vector<string> > partition(string s) {
		vector<vector<string> > solution;
		vector<string> result;

		partition(s, result, solution);
		//print(solution);
		return solution;
	}
	void partition(string s, vector<string> &result, 
					vector<vector<string> > &solution) {
		if (s.length() == 0) {
			solution.push_back(result);
			return;
		}
		for (int len=1; len<=s.length(); len++) {
			string s1 = s.substr(0, len);
			string s2 = s.substr(len, s.length()-len); 
			if ( isPalindrome(s1) ) {
				result.push_back(s1);
				partition(s2, result, solution);
				result.pop_back();
			}
		}
	}
	bool isPalindrome(string s) {
		for (int i=0; i<s.length()/2; i++) {
			if (s[i] != s[s.length()-1-i]) return false;	
		}
		return true;
	}
	void print(vector<vector<string> > &sol) {
		for (int i=0; i<sol.size(); i++) {
			vector<string> res = sol[i];
			for (int j=0; j<res.size(); j++) {
				cout << sol[i][j] << " ";
			}
			cout << endl;
		}
	}
};

int main()
{
	string s("abbb");
	//string s("bb");
	//string s("aba");
	//string s("aba");
	//string s("abbab");
	//string s("");

	Solution S;
	vector<vector<string> >sol = S.partition(s);
}
