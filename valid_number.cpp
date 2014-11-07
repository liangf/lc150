#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
	bool isNumber(const char *s) {
		int start = 0, end = strlen(s)-1;
		bool dot, e, num;
		dot = e = num = false;
		for (; start<strlen(s); start++) {
			if (s[start] != ' ') break;
		}
		for (; end>=0; end--) {
			if (s[end] != ' ') break;
		}
		if (s[start]=='+' || s[start]=='-') start++;
		if (start > end) return false;
		for (int i=start; i<=end; i++) {
			if ('0'<=s[i] && s[i]<='9') {
				num = true;
			}
			else if (s[i]=='e' || s[i]=='E') {
				if (e || !num || i==end) return false;
				e = true;
			}
			else if (s[i] == '.') {
				if (dot || e) return false;
				if (!num && i==end) return false;
				dot = true;	
			}
			else if (s[i]=='+' || s[i]=='-') {
				if (i==end) return false;
				if (s[i-1]!='e' && s[i-1]!='E') return false;
			}
			else return false;
		}
		return true;
	}
};

int main()
{
	//char s[10] = "0";
	//char s[10] = "0.1";
	//char s[10] = "abc";
	//char s[10] = "1a";
	//char s[10] = "1.2e10";
	//char s[10] = "  1  ";
	//char s[10] = ".1";
	//char s[10] = "3.";
	//char s[10] = "3e";
	//char s[10] = "3e+";
	//char s[20] = " 005047e+6";
	char s[20] = "-123.E+5";

	Solution S;
	cout << S.isNumber(s) << endl;
}
