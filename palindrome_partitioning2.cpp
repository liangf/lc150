#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
	int minCut(string s) {
		if (s.length() == 0) return 0;
		vector<vector<bool> > P(s.length(),vector<bool>(s.length(),false));
		vector<int> dp(s.length(), INT_MAX);
		for (int i=0; i<s.length(); i++) {
			for (int j=0; j<=i; j++) {
				if (s[i]==s[j]) {
					P[i][j] = true;
					if (i-1 >= j+1) {
						if ( !P[i-1][j+1] ) P[i][j] = false;
					}
				}	
			}
		}	
		for (int i=0; i<s.length(); i++) {
			if ( P[i][0] ) { dp[i] = 0; continue; }
			for (int j=0; j<i; j++) {
				if (P[i][j+1]) {
					if (dp[j]+1<dp[i]) dp[i] = dp[j] + 1;
				} 	
			}
		}	
		return dp[s.length()-1];
	}
};

int main()
{
	//string s = "aabba";
	//string s = "abba";
	string s = "abb";

	Solution S;
	cout << S.minCut(s) << endl;
}
