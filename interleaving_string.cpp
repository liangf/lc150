#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.length()+s2.length() != s3.length()) return false;

		int m = s1.length(), n = s2.length();
		vector<vector<bool> > dp(m+1, vector<bool>(n+1, false));
		for (int i=0; i<=m; i++) {
			for (int j=0; j<=n; j++) {
				if (i==0 && j==0) dp[i][j] = true;
				if (i>0 && dp[i-1][j] && s3[i+j-1]==s1[i-1]) dp[i][j]=true;
				if (j>0 && dp[i][j-1] && s3[i+j-1]==s2[j-1]) dp[i][j]=true;
			}
		}
		return dp[m][n];
	}
};

int main()
{
	string s1 = "aabcc";
	string s2 = "dbbca";
	//string s3 = "aadbbcbcac";
	string s3 = "aadbbbaccc";

	Solution s;
	cout << s.isInterleave(s1, s2, s3) << endl;
}
