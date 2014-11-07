#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
/*
class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		sort(num.begin(), num.end());
		vector<int> result;
		vector<vector<int> > solution;
		dfs(num, 0, 0, result, solution, 0);
		return solution;
	}
	void dfs(vector<int> &num, int step, int start, vector<int> &result,
				vector<vector<int> > &solution, int target) {
		if (step == 3) {
			if(target == 0) solution.push_back(result);
			return;
		}
		unordered_map<int, bool> umap;
		for (int i=start; i<num.size(); i++) {
			if (umap.find(num[i]) == umap.end()) {
				umap[ num[i] ] = true;
				result.push_back(num[i]);
				dfs(num, step+1, i+1, result, solution, target+num[i]);
				result.pop_back();
			}
		}
	}
};*/

class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		sort(num.begin(), num.end());
		vector<vector<int> > solution;
		int len = num.size();
		for (int left=0; left < len-2; left++) {
			int right = num.size() - 1;	
			for (int mid=left+1; mid<right; ) {
				int sum = num[left] + num[mid] + num[right];
				if (sum == 0) {
					vector<int> result;
					result.push_back(num[left]);
					result.push_back(num[mid]);
					result.push_back(num[right]);
					solution.push_back(result);
					while (mid<right && num[mid]==num[mid+1]) mid++;
					mid = mid + 1;
					while (right>mid && num[right]==num[right-1]) right--;
					right = right - 1;
				}
				else if (sum < 0) mid++;
				else right--; 
			}	
			while (left<right-1 && num[left]==num[left+1]) left++;
		}	
		return solution;
	}
};

int main()
{
	vector<int> num;
/*	num.push_back(-1);
	num.push_back(0);
	num.push_back(1);
	num.push_back(2);
	num.push_back(-1);
	num.push_back(-4);
*/	
	Solution s;
	vector<vector<int> > sol = s.threeSum(num);
	for (int i=0; i<sol.size(); i++) {
		for (int j=0; j<sol[i].size(); j++) {
			cout << sol[i][j] << " "; 
		}
		cout << endl;
	}
}
