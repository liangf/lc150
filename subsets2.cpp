#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		sort(S.begin(), S.end());
		vector<int> result;
		vector<vector<int> > solution;

		for (int i=0; i<=S.size(); i++) {
			int pre = INT_MAX;	
			dfs(pre, S, i, result, solution, 0);
		}	
		return solution;
	} 
	void dfs(int &pre, vector<int> &S, int n, vector<int> &result,
				vector<vector<int> > &solution, int start) {
		if (n == result.size()) {
			solution.push_back(result);
			return;	
		}
		
		for (int i=start; i<S.size(); i++) {
			if (pre == S[i]) continue;
			result.push_back(S[i]);
			dfs(pre, S, n, result, solution, i+1);	
			pre = S[i];
			result.pop_back();
		}
	}
};

int main()
{
	vector<int> vec;
	vec.push_back(2);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(1);
	vec.push_back(3);

	Solution s;
	vector<vector<int> > solution;
	solution = s.subsetsWithDup(vec);
	for (int i=0; i<solution.size(); i++) {
		for (int j=0; j<solution[i].size(); j++) {
			cout << solution[i][j] << " ";
		}
		cout << endl;
	}
}
