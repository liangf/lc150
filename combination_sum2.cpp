#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
		vector<int> result;
		vector<vector<int> > solution;
		vector<bool> visited(candidates.size(), false);
		sort(candidates.begin(), candidates.end());
		dfs(0, candidates, target, visited, result, solution);
		return solution;
	}
	void dfs(int start, vector<int> &candidates, int target, vector<bool> &visited, vector<int> &result, vector<vector<int> > &solution) {
		if (target == 0) {
			solution.push_back(result);
			return;
		}		
		if (target < 0) return;
		unordered_map<int, bool> umap;
		for (int i=start; i<candidates.size(); i++) {
			if ( !visited[i] ) {
				if (umap.find(candidates[i]) == umap.end()) {
					umap[ candidates[i] ] = true;
					visited[i] = true;
					result.push_back(candidates[i]);	
					dfs(i, candidates, target-candidates[i], visited, result, solution);
					result.pop_back();
					visited[i] = false;
				}
			}
		}
	}
};


int main()
{
	vector<int> candidates;
/*	candidates.push_back(1);
	candidates.push_back(1);
	candidates.push_back(1);
	candidates.push_back(2);
*/
	candidates.push_back(10);
	candidates.push_back(1);
	candidates.push_back(2);
	candidates.push_back(7);
	candidates.push_back(6);
	candidates.push_back(1);
	candidates.push_back(5);
	Solution s;
	vector<vector<int> > sol = s.combinationSum2(candidates, 8);
	for (int i=0; i<sol.size(); i++) {
		for (int j=0; j<sol[i].size(); j++) {
			cout << sol[i][j] << " ";
		}
		cout << endl;
	}
}
