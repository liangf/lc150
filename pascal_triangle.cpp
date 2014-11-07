#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int> > vec;
		if (numRows == 0) return vec;
 
		vector<int> row;
		row.push_back(1);
		vec.push_back(row);
		if (numRows == 1) return vec;
		
		row.clear();
		row.push_back(1);
		row.push_back(1);
		vec.push_back(row);
		if (numRows == 2) return vec;
		for (int i=2; i<numRows; i++) {
			row.clear();
			vector<int> tmp = vec[i-1];
			// push the 1st element '1'
			row.push_back(1);
			for (int j=1; j<tmp.size(); j++) {
				row.push_back(tmp[j-1]+tmp[j]);	
			}	
			// push the last element '1'
			row.push_back(1);
			vec.push_back(row);
		}
		return vec;
	}		
};

int main()
{
	Solution s;
	vector<vector<int> > vec = s.generate(5);
	for (int i=0; i<vec.size(); i++) {
		vector<int> tmp = vec[i];
		for (int j=0; j<tmp.size(); j++) {
			cout << tmp[j] << " ";
		}
		cout << endl;
	}
}
