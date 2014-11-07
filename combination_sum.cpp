#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		vector<int> result;
		vector<vector<int> > solution;
		sort(candidates.begin(), candidates.end());
		dfs(0, candidates, target, result, solution);
		return solution;
	}
	void dfs(int start, vector<int> &candidates, int target,
			vector<int> &result, vector<vector<int> > &solution) {
		if (target == 0) {
			solution.push_back(result);
			return;
		}		
		if (target < 0) return;
		unordered_map<int, bool> umap;
		for (int i=start; i<candidates.size(); i++) {
			if (umap.find(candidates[i]) == umap.end()) {
				umap[ candidates[i] ] = true;
				result.push_back(candidates[i]);	
				dfs(i, candidates, target-candidates[i], result, solution);
				result.pop_back();
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
	candidates.push_back(8);
	candidates.push_back(7);
	candidates.push_back(4);
	candidates.push_back(3);
	Solution s;
	vector<vector<int> > sol = s.combinationSum(candidates, 11);
	for (int i=0; i<sol.size(); i++) {
		for (int j=0; j<sol[i].size(); j++) {
			cout << sol[i][j] << " ";
		}
		cout << endl;
	}
}
