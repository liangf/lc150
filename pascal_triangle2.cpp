#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> vec;
		vec.resize(rowIndex+1);
		for (int i=0; i<rowIndex+1; i++) vec[i] = 1;
		
		for (int i=1; i<rowIndex+1; i++) {
			for (int j=i-1; j>=1; j--) {
				vec[j] = vec[j-1] + vec[j];	
			}
		}
		return vec;	
	}
};

int main()
{
	Solution s;
	vector<int> vec = s.getRow(4);
	for (int i=0; i<vec.size(); i++) cout << vec[i] << " ";
	cout << endl;
}
