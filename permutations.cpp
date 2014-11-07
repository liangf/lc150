#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int> > res;
		if (num.size() == 0) return res;

		vector<bool> visited(num.size(), false);
		vector<int> row;

		help(num, visited, row, res);
		return res;
	}
	void help(vector<int> &num, vector<bool> &visited, 
				vector<int> &row, vector<vector<int> > &res) {
		if (row.size() == num.size()) {
			res.push_back(row);
			return;
		}

		for (int i=0; i<num.size(); i++) {
			if ( !visited[i] ) {
				visited[i] = true;
				row.push_back(num[i]);
				help(num, visited, row, res);
				visited[i] = false;
				row.pop_back();
			}
		}
	}
};

int main()
{
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);

	Solution s;
	vector<vector<int> > vec = s.permute(num);
	for (int i=0; i<vec.size(); i++) {
		for (int j=0; j<vec[i].size(); j++) {
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
}
