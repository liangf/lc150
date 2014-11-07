#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		string s1 = "";
		for (int i=0; i<s.size(); i++) {
			if ('a'<=s[i] && s[i]<='z') {
				s1 += s[i];
			}
			if ('A'<=s[i] && s[i]<='Z') {
				s1 += s[i] + 32;
			}
			if ('0'<=s[i] && s[i]<='9') {
				s1 += s[i];
			}
		}
		//cout << s1 << endl;
		for (int i=0; i<s1.size()/2; i++) {
			if (s1[i] != s1[s1.size()-1-i])	return false;
		}
		return true;
	}
};

int main()
{
	//string s = "A man, a plan, a canal: Panama";
	//string s = "race a car";
	string s = "1a2";
	
	Solution S;
	cout << S.isPalindrome(s) << endl;
}
