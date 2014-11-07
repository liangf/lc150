#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
class Solution {
public:
	int numDecodings(string s) {
		int result = 0;
		dfs(s, 0, result);
		return result;
	}
	void dfs(string s, int start, int &result) {
		if (start > s.length()) return;
		if (start == s.length()) {
			result++;
			return;
		}
		if (s[start]<='9' && s[start]>='1') dfs(s, start+1, result);
		if (start+1 < s.length()) {
			int a = (s[start]-'0')*10 + s[start+1]-'0';
			if (a <= 26) dfs(s, start+2, result);	
		}
	}
};
*/
class Solution {
public:
	int numDecodings(string s) {
		if (s.length() == 0) return 0;
		vector<int> dp(s.length()+1, 0);
		dp[0] = 1;
		for (int i=1; i<=s.length(); i++) {
			if (s[i-1]<='0' || s[i-1]>'9') dp[i] = 0;
			else dp[i] = dp[i-1];
			if (i-2 >= 0) {
				int a = (s[i-2]-'0')*10 + s[i-1]-'0';
				if (a<=26 && a>=10) dp[i] += dp[i-2];
			}
		}	
		return dp[s.length()];
	}
};

int main()
{
	//string s = "123";
	//string s = "1";
	//string s = "0";
	//string s = "10";
	string s = "101";
	Solution S;
	cout << S.numDecodings(s) << endl;
}
