#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> fullJustify(vector<string> &words, int L) {
		vector<string> result;
		if (words.size() == 0) return result;
		int pre=0, row_len=0;
		for (int i=0; i<words.size(); i++) {
			row_len += words[i].length();
			if (row_len+i-pre > L) {
				int nspace=0, nremain=0;
				string row = "", space = "";
				row_len -= words[i].length();
				if (i-1 != pre) {
					nspace = (L-row_len)/(i-1-pre);
					nremain = (L-row_len)%(i-1-pre);
					space.resize(nspace, ' ');
				}
				for (int j=pre; j<=i-1; j++) {
					row += words[j];
					if (j != i-1) {
						row += space;
						if (nremain-- > 0) row += " ";	
					}
				}
				while (row.length() < L) {
					row += " ";
				}
				result.push_back(row);	
				pre = i;
				row_len = 0;
				i--;
			}
		}
		string row = "";
		for (int i=pre; i<words.size(); i++) {
			row += words[i];
			if (row.length() < L) row += " ";
		}
		while (row.length() < L) {
			row += " ";
		}
		result.push_back(row);
		return result;
	}
};

int main()
{
	vector<string> words;
/*
	words.push_back("This");
	words.push_back("is");
	words.push_back("an");
	words.push_back("example");
	words.push_back("of");
	words.push_back("text");
	words.push_back("justification.");
*/

	words.push_back("a");
	words.push_back("b");
	words.push_back("c");
	words.push_back("d");
	words.push_back("e");
	words.push_back("f");

/*
	words.push_back("Listen");
	words.push_back("to");
	words.push_back("many,");
	words.push_back("speak");
	words.push_back("to");
	words.push_back("a");
	words.push_back("few.");
*/
	Solution s;
	vector<string> res = s.fullJustify(words, 5);

	for (int i=0; i<res.size(); i++) {
		cout << res[i] << "|" << endl;
	}
}
