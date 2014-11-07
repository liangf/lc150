#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		if (num.size() == 0) return 0;
		unordered_map<int, bool> umap;
		int longest = 1;

		for (int i=0; i<num.size(); i++) {
			umap[num[i]] = true;
		}
		for (int i=0; i<num.size(); i++) {
			int cur = num[i];
			int pre = cur - 1;
			int next = cur + 1;
			int count = 1;
			//cout << pre << " " << cur << " " << next << endl;
			while ( umap[pre] ) {
				count++;
				umap.erase(pre);
				pre = pre - 1;
			}
			while ( umap[next] ) {
				count++;
				umap.erase(next);
				next = next + 1;
			}
			if (count > longest) longest = count;
		}
		return longest;
	}
};


int main()
{
	vector<int> num;
	num.push_back(100);
	num.push_back(4);
	num.push_back(200);
	num.push_back(1);
	num.push_back(3);
	num.push_back(2);
	
	Solution s;
	cout << s.longestConsecutive(num) << endl;
}
