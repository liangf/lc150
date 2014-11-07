#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int totalNQueens(int n) {
		vector<int> rowQ(n, -1);
		int sum = 0;
		dfs(n, rowQ, 0, sum);
		return sum;
	}
	void dfs(int n, vector<int> &rowQ, int row, int &sum) {
		if (n == row) {
			sum++;
			return;
		}
		for (int col=0; col<n; col++) {
			rowQ[row] = col;
			if ( place(rowQ, row, col) ) {
				dfs(n, rowQ, row+1, sum);
			}
		}
	}
	bool place(vector<int> &rowQ, int row, int col) {
		for (int i=0; i<row; i++) {
			if (col==rowQ[i] || abs(row-i)==abs(col-rowQ[i])) {
				return false;
			}	
		}
		return true;
	}
};

int main()
{
	Solution s;
	cout << s.totalNQueens(4) << endl;
}
