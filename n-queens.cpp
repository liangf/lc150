#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<string> > solveNQueens(int n) {
		vector<int> rowQ(n, -1);
		vector<string> result;
		vector<vector<string> > solution;
		dfs(n, rowQ, result, solution, 0);
		return solution;
	}
	void dfs(int n, vector<int> &rowQ, vector<string> &result,
				vector<vector<string> > &solution, int i) {
		if (i == n) {
			solution.push_back(result);
			return;
		}
		for (int j=0; j<n; j++) {
			if (rowQ[j]<0 && place(rowQ, i, j)) {
					string s(n, '.');
					s[j] = 'Q';
					rowQ[j] = i;
					result.push_back(s);
					dfs(n, rowQ, result, solution, i+1);
					rowQ[j] = -1;
					result.pop_back();
			}
		}
	}
	bool place(vector<int> &rowQ, int row, int col) {
		for (int j=0; j<rowQ.size(); j++) {
			if (rowQ[j] >= 0) {
				if (abs(row-rowQ[j]) == abs(col-j)) { 
					return false;
				}
			}
		}
		return true;
	}
};

int main()
{
	Solution s;
	vector<vector<string> > sol = s.solveNQueens(4);

	for (int i=0; i<sol.size(); i++) {
		for (int j=0; j<sol[i].size(); j++) {
			cout << sol[i][j] << endl;
		}
		cout << "-----------------------------\n";
	}
}
