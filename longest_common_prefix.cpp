#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		if (strs.size() == 0) return "";
		string longest = strs[0];
		for (int i=1; i<strs.size(); i++) {
			for (int j=0; j<longest.length(); j++) {
				if (strs[i][j] != strs[0][j]) {
					if (j < longest.length()) {
						longest = strs[i].substr(0, j);	
					}
					break;
				}
			}
		}
		return longest;
	}
};


int main()
{
	vector<string> strs;
	strs.push_back("abcd");
	strs.push_back("abcc");
	strs.push_back("abdd");
	strs.push_back("abaa");

	Solution s;
	cout << s.longestCommonPrefix(strs) << endl;
}
