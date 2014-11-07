#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		string result;
		vector<string> solution;

		dfs(s, 0, 0, result, solution);	
		return solution;
	}
	void dfs(string &s, int start, int count, string &result, 
				vector<string> &solution) {
		if (count == 4) {
			if (result.length() == s.length()+4) {
				solution.push_back(result.substr(0, result.length()-1));
			}
			return;
		}	
		if (start+1<=s.length() && isValidIp(s.substr(start, 1))) {
			result += s.substr(start, 1) + ".";
			dfs(s, start+1, count+1, result, solution);
			result = result.substr(0, result.length()-2);
		}
		if (start+2<=s.length() && isValidIp(s.substr(start, 2))) {
			result += s.substr(start, 2) + ".";
			dfs(s, start+2, count+1, result, solution);
			result = result.substr(0, result.length()-3);
		}
		if (start+3<=s.length() && isValidIp(s.substr(start, 3))) {
			result += s.substr(start, 3) + ".";
			dfs(s, start+3, count+1, result, solution);
			result = result.substr(0, result.length()-4);
		}
	}
	bool isValidIp(string s) {
		if (s.length()==0 || s.length()==4) return false;
		if (s.length()>1 && s[0]=='0') return false;
		int n_ip = strToInt(s);
		if (0<=n_ip && n_ip<=255) return true;
		return false;
	}
	int strToInt(string &s) {
		int sum = 0;
		for (int i=0; i<s.length(); i++) {
			sum = sum*10 + s[i]-48;
		}
		return sum;
	}
};

int main()
{
	//string s = "25525511135";
	string s = "010010";
	
	Solution S;
	vector<string> vs = S.restoreIpAddresses(s);
	for (int i=0; i<vs.size(); i++) {
		cout << vs[i] << endl;
	}
}
