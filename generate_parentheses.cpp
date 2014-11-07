#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> vec;
		string s;

		if (n == 0) return vec;

		help(s, vec, n, 0, 0);
		return vec;
	}

	void help(string s, vector<string> &vec, int n, 
				int left, int right) {
		if (left>n || right>n) return;
		if (n==left && n==right) {
			vec.push_back(s);
			return;
		}		
		
		s.push_back('(');	
		help(s, vec, n, left+1, right);
		s.erase(s.length()-1);
		if (left > right) {
			s.push_back(')');
			help(s, vec, n, left, right+1);
			s.erase(s.length()-1);
		}
	}
};

int main()
{
	Solution s;
	vector<string> vec = s.generateParenthesis(1);
	for (int i=0; i<vec.size(); i++) cout << vec[i] << endl;
}
