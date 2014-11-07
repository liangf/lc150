#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		if (path.length() <= 0) return "";
		string sol = "";
		vector<string> result;
		int i = path.find('/');
		while (i < path.length()) {
			int j = path.find('/', i+1);
			if (j == string::npos) j = path.length();
			if (j-i-1==2 && path.substr(i+1, 2) == "..") {
				if (!result.empty()) result.pop_back();
			}
			else if (j-i-1==1 && path.substr(i+1, 1) == ".") {}	
			else if (j-i-1<=0) {}	
			else {
				result.push_back(path.substr(i, j-i));
			}
			i = j;
		}	
		for (int k=0; k<result.size(); k++) {
			sol += result[k];
		}
		return result.size()==0 ? "/" : sol;
	}
};

int main()
{
	//string path = "/a/./b/../../c/";
	//string path = "/home//foo/";
	//string path = "/home";
	//string path = "/home/";
	//string path = "/";
	//string path = "/../";
	string path = "/.";
	
	Solution s;
	string sol = s.simplifyPath(path); 
	cout << sol << endl;
}
