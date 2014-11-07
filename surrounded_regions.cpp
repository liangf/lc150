#include <iostream>
#include <vector>
using namespace std;

struct Dir {
	bool up;
	bool right;
	bool down;
	bool left;
	Dir() : up(false), right(false), down(false), left(false) {}
};
/*
class Solution {
public:
	void solve(vector<vector<char> > &board) {
		if (board.size() == 0) return;
		int m = board.size(), n = board[0].size();
		vector<vector<Dir> > dp(m, vector<Dir>(n, Dir()));
		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++) {
				if (board[i][j] == 'X') {
					dp[i][j].up = true;
					dp[i][j].right = true;
					dp[i][j].down = true;
					dp[i][j].left = true;
				}
				else {
					if (i==0) dp[i][j].up = false;
					else dp[i][j].up = dp[i-1][j].up && dp[i-1][j].left;
					if (j==0) dp[i][j].left = false;
					else dp[i][j].left = dp[i][j-1].left && dp[i][j-1].up; 
				}	
			}
		}
		
		for (int i=m-1; i>=0; i--) {
			for (int j=n-1; j>=0; j--) {
				if (board[i][j] == 'X') {
					dp[i][j].up = true;
					dp[i][j].right = true;
					dp[i][j].down = true;
					dp[i][j].left = true;
				}
				else {
					if (j == n-1) dp[i][j].right = false;
					else dp[i][j].right = dp[i][j+1].right && dp[i][j+1].down;
					if (i == m-1) dp[i][j].down = false;
					else dp[i][j].down = dp[i+1][j].down && dp[i+1][j].right;
				}
			}
		}

		cout << "left\n";
		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++) {
				cout << dp[i][j].left << " ";
			}
			cout << endl;
		}
		cout << "up\n";
		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++) {
				cout << dp[i][j].up << " ";
			}
			cout << endl;
		}
		cout << "right\n";
		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++) {
				cout << dp[i][j].right << " ";
			}
			cout << endl;
		}
		cout << "down\n";
		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++) {
				cout << dp[i][j].down << " ";
			}
			cout << endl;
		}

		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++) {
				if (board[i][j] == 'O') {
					//cout << i << "," << j << ":" << dp[i][j].down << endl;
					if (dp[i][j].up && dp[i][j].right && dp[i][j].down && dp[i][j].left) {
						board[i][j] = 'X';
					}
				}
			}
		}
	}
};*/
/*
// Time Limit Exceeded
class Solution {
public:
	void solve(vector<vector<char> > &board) {
		if (board.size() == 0) return;
		int m = board.size(), n = board[0].size();
		vector<vector<bool> > visited(m, vector<bool>(n, false));	
		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++) {
				if (board[i][j]=='O' && !dfs(board, visited, i, j)) {
					board[i][j] = 'X';
				}
			}
		}
	}
	bool dfs(vector<vector<char> > &board, vector<vector<bool> > visited,
				int m, int n) {
		if (m==0 || n==0 || m==board.size()-1 || n==board[0].size()-1) {
			if (board[m][n] == 'O') return true;
		}	
		if (visited[m][n] || board[m][n]=='X') return false;
		bool find = false;
		visited[m][n] = true;
		find = 	dfs(board, visited, m-1, n) || 
				dfs(board, visited, m, n-1) ||
				dfs(board, visited, m+1, n) ||
				dfs(board, visited, m, n+1);
		visited[m][n] = false;
		return find;
	}
};
*/
/*
// Runtime Error
class Solution {
public:
	void solve(vector<vector<char> > &board) {
		if (board.size() == 0) return;
		for (int j=0; j<board[0].size(); j++) {
			fill(board, 0, j);
			fill(board, board.size()-1, j);
		}
		for (int i=0; i<board.size(); i++) {
			fill(board, i, 0);
			fill(board, i, board[0].size()-1);
		}
		for (int i=0; i<board.size(); i++) {
			for (int j=0; j<board[i].size(); j++) {
				if (board[i][j] == 'O') board[i][j] = 'X';
				else if (board[i][j] == '#') board[i][j] = 'O';
			}
		}
	}
	void fill(vector<vector<char> > &board, int m, int n) {
		if (board[m][n] != 'O') return;
		board[m][n] = '#';
		if (m > 0) fill(board, m-1, n);
		if (n > 0) fill(board, m, n-1);
		if (m < board.size()-1) fill(board, m+1, n);
		if (n < board[0].size()-1) fill(board, m, n+1);
	}
};
*/

class Solution {
public:
	void solve(vector<vector<char> > &board) {
		if (board.size() == 0) return;
		int row = board.size(), col = board[0].size();
		for (int i=0; i<col; i++) {
			if (board[0][i] == 'O') {
				board[0][i] = '#';
				dfs(board, 0, i, row, col);
			}
		}		
		for (int i=0; i<col; i++) {
			if (board[row-1][i] == 'O') {
				board[row-1][i] = '#';
				dfs(board, row-1, i, row, col);
			}
		}
		for (int i=0; i<row-1; i++) {
			if (board[i][0] == 'O') {
				board[i][0] = '#';
				dfs(board, i, 0, row, col);
			}
		}	
		for (int i=0; i<row-1; i++) {
			if (board[i][col-1] == 'O') {
				board[i][col-1] = '#';
				dfs(board, i, col-1, row, col);
			}
		}

		for (int i=0; i<board.size(); i++) {
			for (int j=0; j<board[i].size(); j++) {
				if (board[i][j] == 'O') board[i][j] = 'X';
				else if (board[i][j] == '#') board[i][j] = 'O';
			}
		}
	}
	void dfs(vector<vector<char> > &board, int i, int j, 
				int row, int col) {
		if (i > 1 && board[i-1][j] == 'O') {
			board[i-1][j] = '#';
			dfs(board, i-1, j, row, col);
		}
		if (i < row-1 && board[i+1][j] == 'O') {
			board[i+1][j] = '#';
			dfs(board, i+1, j, row, col);
		}
		if (j > 1 && board[i][j-1] == 'O') {
			board[i][j-1] = '#';
			dfs(board, i, j-1, row, col);
		}
		if (j < col-1 && board[i][j+1] == 'O') {
			board[i][j+1] = '#';
			dfs(board, i, j+1, row, col);
		}
	}
};

int main()
{
/*	vector<vector<char> > board;
	vector<char> row;
	row.push_back('O');
	row.push_back('X');
	row.push_back('X');
	row.push_back('O');
	row.push_back('X');
	board.push_back(row);
	row.clear();

	row.push_back('X');
	row.push_back('O');
	row.push_back('O');
	row.push_back('X');
	row.push_back('O');
	board.push_back(row);
	row.clear();

	row.push_back('X');
	row.push_back('O');
	row.push_back('X');
	row.push_back('O');
	row.push_back('X');
	board.push_back(row);
	row.clear();

	row.push_back('O');
	row.push_back('X');
	row.push_back('O');
	row.push_back('O');
	row.push_back('O');
	board.push_back(row);
	row.clear();

	row.push_back('X');
	row.push_back('X');
	row.push_back('O');
	row.push_back('X');
	row.push_back('O');
	board.push_back(row);
*/	
	vector<vector<char> > board;
	vector<char> row;
	row.push_back('X');
	row.push_back('O');
	row.push_back('X');
	row.push_back('O');
	row.push_back('X');
	row.push_back('O');
	row.push_back('O');
	row.push_back('O');
	row.push_back('X');
	row.push_back('O');
	board.push_back(row);
	row.clear();

	row.push_back('X');
	row.push_back('O');
	row.push_back('O');
	row.push_back('X');
	row.push_back('X');
	row.push_back('X');
	row.push_back('O');
	row.push_back('O');
	row.push_back('O');
	row.push_back('X');
	board.push_back(row);
	row.clear();

	row.push_back('O');
	row.push_back('O');
	row.push_back('O');
	row.push_back('O');
	row.push_back('O');
	row.push_back('O');
	row.push_back('O');
	row.push_back('O');
	row.push_back('X');
	row.push_back('X');
	board.push_back(row);
	row.clear();

	row.push_back('O');
	row.push_back('O');
	row.push_back('O');
	row.push_back('O');
	row.push_back('O');
	row.push_back('O');
	row.push_back('X');
	row.push_back('O');
	row.push_back('O');
	row.push_back('X');
	board.push_back(row);
	row.clear();

	row.push_back('O');
	row.push_back('O');
	row.push_back('X');
	row.push_back('X');
	row.push_back('O');
	row.push_back('X');
	row.push_back('X');
	row.push_back('O');
	row.push_back('O');
	row.push_back('O');
	board.push_back(row);
	row.clear();

	row.push_back('X');
	row.push_back('O');
	row.push_back('O');
	row.push_back('X');
	row.push_back('X');
	row.push_back('X');
	row.push_back('O');
	row.push_back('X');
	row.push_back('X');
	row.push_back('O');
	board.push_back(row);
	row.clear();

	row.push_back('X');
	row.push_back('O');
	row.push_back('X');
	row.push_back('O');
	row.push_back('O');
	row.push_back('X');
	row.push_back('X');
	row.push_back('O');
	row.push_back('X');
	row.push_back('O');
	board.push_back(row);
	row.clear();

	row.push_back('X');
	row.push_back('X');
	row.push_back('O');
	row.push_back('X');
	row.push_back('X');
	row.push_back('O');
	row.push_back('X');
	row.push_back('O');
	row.push_back('O');
	row.push_back('X');
	board.push_back(row);
	row.clear();

	row.push_back('O');
	row.push_back('O');
	row.push_back('O');
	row.push_back('O');
	row.push_back('X');
	row.push_back('O');
	row.push_back('X');
	row.push_back('O');
	row.push_back('X');
	row.push_back('O');
	board.push_back(row);
	row.clear();

	row.push_back('X');
	row.push_back('X');
	row.push_back('O');
	row.push_back('X');
	row.push_back('X');
	row.push_back('X');
	row.push_back('X');
	row.push_back('O');
	row.push_back('O');
	row.push_back('O');
	board.push_back(row);
	row.clear();

	for (int i=0; i<board.size(); i++) {
		for (int j=0; j<board[0].size(); j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

	Solution s;
	s.solve(board);		
	cout << "===============================================================\n";	
	for (int i=0; i<board.size(); i++) {
		for (int j=0; j<board[0].size(); j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

}
