#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
class Solution {
public:
	int numDistinct(string S, string T) {
		vector<int> result;
		vector<vector<int> > solution;
		int m = S.length() - 1, n = T.length() - 1;

		help(S, T, m, n, result, solution);	
		for (int i=0; i<solution.size(); i++) {
			result = solution[i];
			for (int j=result.size()-1; j>=0; j--) {
				cout << result[j] << " ";
			}
			cout << endl;
		}
		return solution.size();
	}
	void help(string S, string T, int m, int n, vector<int> &result,
				vector<vector<int> > &solution) {
		if (m < 0) {
			if (result.size() == T.size()) solution.push_back(result);
			return;
		}
		if (S[m] == T[n]) {
			result.push_back(m);
			help(S, T, m-1, n-1, result, solution);
			result.pop_back();
		}
		help(S, T, m-1, n, result, solution);
	}
};*/

class Solution {
public:
	int numDistinct(string S, string T) {
		int m = S.length();
		int n = T.length();
		vector<vector<int> > sol(m+1, vector<int>(n+1, 0));
		for (int i=0; i<=m; i++) {
			sol[i][0] = 1;
		}	

		for (int i=1; i<=m; i++) {
			for (int j=1; j<=n; j++) {
				if (S[i-1] == T[j-1]) sol[i][j] = sol[i-1][j-1]+sol[i-1][j];
				else sol[i][j] = sol[i-1][j];
			}
		}
		return sol[m][n];
	}
};


int main()
{
	string S = "bbb";
	string T = "b";

	//string S = "rabbbit";
	//string T = "rabbit";

	Solution s;
	cout << s.numDistinct(S, T) << endl;
}
