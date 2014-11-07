#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int st = 0, maxlen = 0;
		for (int k=0; k<s.length();) {
			//cout << "k:" << k << endl;
			int i = k - 1, j = k + 1;
			while (i>=0 && s[i]==s[k]) i--;
			while (j<s.length() && s[j]==s[k]) j++;
			k = j;
			while (i>=0 && j<s.length() &&s[i]==s[j]) {
				i--;
				j++;
			}	
			//cout << "i:" << i << " " << "j:" << j << endl;
			if (j-i-1 > maxlen) {
				st = i+1;
				maxlen = j - i - 1;
				//cout << st << " " << maxlen << endl;
			}				
		}
		return s.substr(st, maxlen);
	}
};

int main()
{
	//string s = "abccb";
	string s = "a";
	Solution S;
	cout << S.longestPalindrome(s) << endl;
}
