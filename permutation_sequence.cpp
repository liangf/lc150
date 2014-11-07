#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
/*
class Solution {
public:
	string getPermutation(int n, int k) {
		string result = "";
		vector<string> solution;
		vector<bool> visited(n+1, false);
		dfs(n, 0, visited, result, solution);
		for (int i=0; i<solution.size(); i++) {
			if (i+1 == k) return solution[i];
		}
		return "";
	}
	void dfs(int n, int step, vector<bool> visited, string result, 
				vector<string> &solution) {
		if (step == n) {
			solution.push_back(result);
			return;
		}
		for (int i=1; i<=n; i++) {
			if (!visited[i]) {
				visited[i] = true;
				result.push_back(i+'0');
				dfs(n, step+1, visited, result, solution);
				visited[i] = false;
				result.pop_back();
			}
		}
	}	
};*/

class Solution {
public:
	string getPermutation(int n, int k) {
		vector<int> nums;
		for (int i=0; i<=n; i++) nums.push_back(i);
	
		string result = "";
		while (true) {
			if (n == 1) {
				result.push_back(nums[1]+'0');
				break;
			}
			int n1 = ceil((k+0.0)/fac(n-1));	
			result.push_back(nums[n1]+'0');
			nums.erase(nums.begin()+n1);
			k = k - (n1-1)*fac(n-1);
			n--;
		}
		return result;
	}
	int fac(int n) {
		if (n<=1) return 1;
		else return n * fac(n-1);
	}
};

int main()
{
	Solution s;
	cout << s.getPermutation(4, 15) << endl;
	//cout << s.getPermutation(2, 1) << endl;
	//cout << s.getPermutation(1, 1) << endl;
}
