#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
		vector<string> result, tmp;
		vector<vector<string> > solution, tmp2;	
		if (dict.size() <= 0) return solution;

		dict.insert(start); dict.insert(end); 
		unordered_map<string, vector<vector<string>>> pre;
		unordered_map<string, vector<vector<string>>> cur;
		tmp.push_back(start);
		tmp2.push_back(tmp);
		pre[start] = tmp2;
		while ( pre.size()>0 ) {
			for (auto it=pre.begin(); it!=pre.end(); it++) {
				dict.erase(it->first);
				for (int i=0; i<it->first.length(); i++) {
					string s = it->first;
					for (char c='a'; c<='z'; c++) {
						s[i] = c;
						if (dict.find(s)!=dict.end() && pre.find(s)==pre.end()) {
							solution = it->second;
							for (int j=0; j<solution.size(); j++) {
								result = solution[j];
								result.push_back(s);
								cur[s].push_back( result );
							}
						}
					}
				}
			}	
			if (pre.find(end) != pre.end()) return pre[end];	
			pre = cur;
			cur.clear();
		}
		return solution;
	}
};

int main()
{
	string start = "hit", end = "cog";
	unordered_set<string> dict = {"hot", "dot", "dog", "lot", "log"};

	Solution s;
	vector<vector<string>> sol = s.findLadders(start, end, dict);
	for (int i=0; i<sol.size(); i++) {
		for (int j=0; j<sol[i].size(); j++) {
			cout << sol[i][j] << " ";
		}
		cout << endl;
	}
}
