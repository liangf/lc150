#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	void reverseWords(string &s) {
		trim(s);
		for (int i=0; i<int(s.length())-1; ) {
			if (s[i]==' ' && s[i+1]==' ') {
				s.erase(s.begin()+i);
			}
			else i++;
		}
		s = " " + s;
		reverse(s.begin(), s.end());
		int st = 0;
		for (int i=0; i<s.length(); i++) {
			if (s[i] == ' ') {
				reverse(s.begin()+st, s.begin()+i);
				st = i+1;
			}
		}
		s.pop_back();
	}
	void trim(string &s) {
		if (s.empty()) return;
		if (s.find_first_not_of(" ") != string::npos) {
			s.erase(s.begin(), s.begin()+s.find_first_not_of(" "));
		}
		else s.clear();
		if (s.find_last_not_of(" ") != string::npos) {
			s.erase(s.begin()+s.find_last_not_of(" ")+1, s.end());
		}
		else s.clear();
	}
};

int main()
{
	string s = "  the   sky is    blue  ";
	//string s = " ";
	cout << "[" << s << "]" << endl;
	Solution S;
	S.trim(s);
	cout << "[" << s << "]" << endl;
	
	S.reverseWords(s);
	cout << "[" << s << "]" << endl;
}
