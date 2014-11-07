#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isScramble(string s1, string s2) {
		if (s1.length() != s2.length()) return false;
		return dfs(s1, s2);
	}
	bool dfs(string s1, string s2) {
		if (s1 == s2) return true;	
		vector<char> h(26, 0);
		for (int i=0; i<s1.length(); i++) {
			h[s1[i] - 'a']++;
			h[s2[i] - 'a']--;
		}
		for (int i=0; i<h.size(); i++) {
			if (h[i] != 0) return false;
		}
		for (int i=1; i<s1.length(); i++) {
			string s11 = s1.substr(0, i);
			string s12 = s1.substr(i);
			string s21 = s2.substr(0, i);
			string s22 = s2.substr(i);
			string s23 = s2.substr(0, s12.length());
			string s24 = s2.substr(s12.length());
			bool r = dfs(s11, s21) && dfs(s12, s22) ||
						dfs(s11, s24) && dfs(s12, s23);
			if (r == true) return r;
		}
		return false;
	}
};

int main()
{
	string s1 = "great";
	//string s2 = "great";
	//string s2 = "rgeat";
	string s2 = "rgtae";
	Solution s;
	cout << s.isScramble(s1, s2) << endl;
}
