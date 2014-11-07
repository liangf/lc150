#include <iostream>
#include <vector>
using namespace std;
/*
class Solution {
public:
	bool exist(vector<vector<char> > &board, string word) {
		if (board.size()==0 || word.length()==0) return false;
		int m = board.size(), n = board[0].size();
		vector<vector<bool> > visited(m, vector<bool>(n, false));
		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++) {
				if (word[0]== board[i][j]) {
					//cout <<i << "," << j << ":"<< word[0] << endl;
					visited[i][j] = true;
					if (dfs(board, word, visited, i, j, 0)) return true;
					visited[i][j] = false;
				}
			}
		}
		return false;
	}
	bool dfs(vector<vector<char> > &board, string &word, 
				vector<vector<bool> > &visited, int i, int j, int k) {
		//cout << i << " " << j << " " << k << endl;
		if (k == word.length()-1) return true;
		bool right=false, down=false, left=false, up=false;
		if (j+1<board[0].size()&&!visited[i][j+1]&&word[k+1]==board[i][j+1]) {
			visited[i][j+1] = true;
			right = dfs(board, word, visited, i, j+1, k+1);
			visited[i][j+1] = false;
		}
		if (!right && i+1<board.size()&&!visited[i+1][j]&&word[k+1]==board[i+1][j]) {
			visited[i+1][j] = true;
			down = dfs(board, word, visited, i+1, j, k+1);
			visited[i+1][j] = false;
		}
		if (!right && !down && j-1>=0&&!visited[i][j-1]&&word[k+1]==board[i][j-1]) {
			visited[i][j-1] = true;
			left = dfs(board, word, visited, i, j-1, k+1);
			visited[i][j-1] = false;
		}
		if (!right && !down && !left && i-1>=0&&!visited[i-1][j]&&word[k+1]==board[i-1][j]) {
			visited[i-1][j] = true;
			up = dfs(board, word, visited, i-1, j, k+1);
			visited[i-1][j] = false;
		}
		return right || down || left || up;
	}
};*/
/*
class Solution {
public:
	bool exist(vector<vector<char> > &board, string word) {
		if (board.size()==0 || word.length()==0) return false;
		int m = board.size(), n = board[0].size();
		vector<vector<bool> > visited(m, vector<bool>(n, false));
		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++) {
				if (dfs(board, word, visited, i, j, 0)) return true;
			}
		}
		return false;
	}
	bool dfs(vector<vector<char> > &board, string &word, 
				vector<vector<bool> > &visited, int i, int j, int k) {
		if (k == word.length()) return true;
		if (i<0||j<0||i>=board.size()||j>=board[0].size()) return false;
		bool right=false, down=false, left=false, up=false;
		if (!visited[i][j] && word[k]==board[i][j]) {
			visited[i][j] = true;
			right = dfs(board, word, visited, i, j+1, k+1);
			if (!right)
				down = dfs(board, word, visited, i+1, j, k+1);
			if (!right && !down)
				left = dfs(board, word, visited, i, j-1, k+1);
			if (!right && !down && !left)
				up = dfs(board, word, visited, i-1, j, k+1);
			visited[i][j] = false;
		}
		return right || down || left || up;
	}
};
*/

class Solution {
public:
	bool exist(vector<vector<char> > &board, string word) {
		if (board.size()==0 || word.length()==0) return false;
		int m = board.size(), n = board[0].size();
		vector<vector<bool> > visited(m, vector<bool>(n, false));
		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++) {
				if (dfs(board, word, visited, i, j, 0)) return true;
			}
		}
		return false;
	}
	bool dfs(vector<vector<char> > &board, string &word, 
				vector<vector<bool> > &visited, int i, int j, int k) {
		if (k == word.length()) return true;
		if (i<0||j<0||i>=board.size()||j>=board[0].size()) return false;
		if (visited[i][j] || word[k]!=board[i][j]) return false;
		bool find =	false;
		visited[i][j] = true;
		find = 	dfs(board, word, visited, i, j+1, k+1) ||
				dfs(board, word, visited, i+1, j, k+1) ||
				dfs(board, word, visited, i, j-1, k+1) ||
				dfs(board, word, visited, i-1, j, k+1);
		visited[i][j] = false;
		return find;	
	}
};

int main()
{
	vector<vector<char> > board;
	vector<char> row;
/*
	row.push_back('A');
	row.push_back('B');
	row.push_back('C');
	row.push_back('E');
	board.push_back(row);
	row.clear();

	row.push_back('S');
	row.push_back('F');
	row.push_back('C');
	row.push_back('S');
	board.push_back(row);
	row.clear();
	
	row.push_back('A');
	row.push_back('D');
	row.push_back('E');
	row.push_back('E');
	board.push_back(row);
*/
	row.push_back('A');
	row.push_back('B');
	row.push_back('C');
	row.push_back('E');
	board.push_back(row);
	row.clear();

	row.push_back('S');
	row.push_back('F');
	row.push_back('E');
	row.push_back('S');
	board.push_back(row);
	row.clear();
	
	row.push_back('A');
	row.push_back('D');
	row.push_back('E');
	row.push_back('E');
	board.push_back(row);

	//string word = "SEE";
	//string word = "ABCB";
	string word = "ABCEFSADEESE";

	Solution s;
	cout << s.exist(board, word) << endl;
}
