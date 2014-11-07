#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum direction { Left = 1, Up, Leftup};

class Solution {
public:
	void longestCommonSubseq(string s, string t) {
		s = "#" + s;
		t = "#" + t;
		int m = s.length();
		int n = t.length();
		vector<vector<int> > lcs(m, vector<int>(n,0));
		vector<vector<int> > dir(m, vector<int>(n, 0));

		for (int i=1; i<m; i++) {
			for (int j=1; j<n; j++) {
				if (s[i] == t[j]) {
					lcs[i][j] = lcs[i-1][j-1] + 1;
					dir[i][j] = Leftup;
				}
				else {
					if (lcs[i-1][j] > lcs[i][j-1]) {
						lcs[i][j] = lcs[i-1][j];
						dir[i][j] = Up;
					}
					else {
						lcs[i][j] = lcs[i][j-1];
						dir[i][j] = Left;
					}
				}	
			}
		}
		for (int j=2; j<n; j++) {
			dir[1][j] = Left;
		}
		for (int i=2; i<m; i++) {
			dir[i][1] = Up;
		}
		for (int i=1; i<m; i++) {
			for (int j=1; j<n; j++) {
				if (dir[i][j] == Left) cout << "=";
				else if (dir[i][j] == Up) cout << "|";
				else cout << "\\";
				cout << lcs[i][j] << " ";
			}
			cout << endl;
		}

		// print the longest common subsequence
		vector<int> result;
		track_lcs(dir, m-1, n-1, result);

		for (int i=result.size()-1; i>=0; i--) {
			cout << s[result[i]];
		}
		cout << endl;

	}
	void track_lcs(vector<vector<int> > &dir, int m, int n, 
					vector<int> &result) {
		if (m==0 && n==0) return;
		if (dir[m][n] == Leftup) {
			result.push_back(m);
			track_lcs(dir, m-1, n-1, result);
		}
		if (dir[m][n] == Left) track_lcs(dir, m, n-1, result);
		if (dir[m][n] == Up) track_lcs(dir, m-1, n, result);
	}
};

int main()
{
	//string s = "GCCCTAGCG";
	//string t = "GCGCAATG";
	string s = "rabbit";
	string t = "rabbbit";
	
	Solution S;
	S.longestCommonSubseq(s, t);
}
