#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<vector<int> > permuteUnique(vector<int> &num) {
		vector<bool> visited(num.size(), false);
		vector<int> result;
		vector<vector<int> > solution;
		dfs(num, 0, visited, result, solution);
		return solution;
	}
	void dfs(vector<int> &num, int step, vector<bool> &visited,
			vector<int> &result, vector<vector<int> > &solution) {
			if (step == num.size()) {
				solution.push_back(result);
				return;
			}
			unordered_map<int, bool> umap;
			for (int i=0; i<num.size(); i++) {
				if ( !visited[i] ) {
					if (umap.find(num[i]) == umap.end()) {
						umap[ num[i] ] = true;
						visited[i] = true;
						result.push_back(num[i]);
						dfs(num, step+1, visited, result, solution);
						result.pop_back();
						visited[i] = false;
					}
				}
			}
	}
};


int main()
{
	vector<int> num;
	num.push_back(1);
	num.push_back(1);
	num.push_back(3);
	Solution s;
	vector<vector<int> > sol = s.permuteUnique(num);
	for (int i=0; i<sol.size(); i++) {
		for (int j=0; j<sol[i].size(); j++) {
			cout << sol[i][j] << ",";
		}
		cout << endl;
	}
}
