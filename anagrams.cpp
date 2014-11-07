#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<string> anagrams(vector<string> &strs) {
		vector<string> result;
		unordered_map<string, vector<string> > group;
		for (int i=0; i<strs.size(); i++) {
			string sort_s = strs[i];
			sort(sort_s.begin(), sort_s.end());	
			if ( group.find(sort_s) == group.end() ) {
				group[sort_s] = vector<string>(1, strs[i]);
			}		 
			else {
				group[sort_s].push_back(strs[i]);
			}
		}
		for (auto it=group.begin(); it!=group.end(); it++) {
			vector<string> vs = it->second;	
			if (vs.size() > 1) {
				for (int i=0; i<vs.size(); i++) {
					result.push_back(vs[i]);
				}
			}	
		}
		return result;
	}
};

int main()
{
	vector<string> strs;
	strs.push_back(string("ab"));
	strs.push_back(string("bca"));
	strs.push_back(string("ba"));
	strs.push_back(string("bbb"));
	strs.push_back(string("abc"));
	
	Solution s;
	strs = s.anagrams(strs);
	for (int i=0; i<strs.size(); i++) {
		cout << strs[i] << endl;
	}
}
