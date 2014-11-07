#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		unordered_map<char, string> umap;
		umap['1'] = "";
		umap['2'] = "abc";
		umap['3'] = "def";
		umap['4'] = "ghi";
		umap['5'] = "jkl";
		umap['6'] = "mno";
		umap['7'] = "pqrs";
		umap['8'] = "tuv";
		umap['9'] = "wxyz";
		umap['0'] = " ";
		string result = "";
		vector<string> solution;
		dfs(digits, 0, umap, result, solution);
		return solution;		
	}
	void dfs(string &digits, int step, unordered_map<char, string> &umap,
				string &result, vector<string> &solution) {
		if (step == digits.length()) {
			solution.push_back(result);
			return;
		}
		string s = umap[ digits[step] ];
		for (int i=0; i<s.length(); i++) {
			result.push_back(s[i]);		
			dfs(digits, step+1, umap, result, solution);
			result.pop_back();
		}	
	}
};

int main()
{
	string digits = "23";
	//string digits = "12";
	Solution s;
	vector<string> sol = s.letterCombinations(digits);
	for (int i=0; i<sol.size(); i++) {
		cout << sol[i] << endl;
	}
}
