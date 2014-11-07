#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > generateMatrix(int n) {
		vector<vector<int> > matrix(n, vector<int>(n, 0));
		int count = 1;
		for (int layer=0; layer<(n+1)/2; layer++) {
			for (int j=layer; j<n-layer; j++) {
				matrix[layer][j] = count++;
			}
			for (int i=layer+1; i<n-layer; i++) {
				matrix[i][n-1-layer] = count++;
			}
			for (int j=n-1-1-layer; j>=layer; j--) {
				matrix[n-1-layer][j] = count++;
			}
			for (int i=n-1-1-layer; i>=layer+1; i--) {
				matrix[i][layer] = count++;
			}
		}
		return matrix;
	}
};


int main()
{
	Solution s;
	vector<vector<int> > matrix = s.generateMatrix(1);

	for (int i=0; i<matrix.size(); i++) {
		for (int j=0; j<matrix[i].size(); j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
