#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > subsets(vector<int> &S) {
		sort(S.begin(), S.end());
		vector<int> result;
		vector<vector<int> > solution;
		
		for (int i=0; i<=S.size(); i++) {
			dfs(S, i, result, solution, 0);
		}	
		return solution;
	} 
	void dfs(vector<int> &S, int n, vector<int> &result,
				vector<vector<int> > &solution, int start) {
		if (n == result.size()) {
			solution.push_back(result);
			return;	
		}
		
		for (int i=start; i<S.size(); i++) {
			result.push_back(S[i]);
			dfs(S, n, result, solution, i+1);	
			result.pop_back();
		}
	}
};

int main()
{
	vector<int> vec;
	vec.push_back(4);
	vec.push_back(1);
	vec.push_back(0);

	Solution s;
	vector<vector<int> > solution;
	solution = s.subsets(vec);
	for (int i=0; i<solution.size(); i++) {
		for (int j=0; j<solution[i].size(); j++) {
			cout << solution[i][j] << " ";
		}
		cout << endl;
	}
}
