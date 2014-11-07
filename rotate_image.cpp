#include <iostream>
#include <vector>
using namespace std;
/*
class Solution {
public:
	void rotate(vector<vector<int> > &matrix) {
		if (matrix.size() == 0) return;
		
		int n = matrix.size();
		int layer = (n+1)/2;
		for (int k=0; k<layer; k++) {
			for (int i=0; i<n-2*k-1; i++) {
				//cout << matrix[k][k+i] << " " << matrix[n-1-k-i][k] << " " << matrix[n-1-k][n-1-k-i] << " " << matrix[k+i][n-1-k] << endl;
				int tmp = matrix[k][k+i];
				matrix[k][k+i] = matrix[n-1-k-i][k];
				matrix[n-1-k-i][k] = matrix[n-1-k][n-1-k-i];
				matrix[n-1-k][n-1-k-i] = matrix[k+i][n-1-k];
				matrix[k+i][n-1-k] = tmp;	
			}
		}	
	}
};
*/
class Solution {
public:
	void rotate(vector<vector<int> > &matrix) {
		if (matrix.size() == 0) return;
		int n = matrix.size();

		for (int i=0; i<n; i++) {
			for (int j=0; j<i; j++) {
				swap(matrix[i][j], matrix[j][i]);
			}
		}	
		for (int i=0; i<n; i++) {
			for (int j=0; j<n/2; j++) {
				swap(matrix[i][j], matrix[i][n-1-j]);	
			}
		}
	}
};


int main()
{
	vector<int> row;
	vector<vector<int> > vec;
	row.push_back(1);
	row.push_back(2);
	row.push_back(3);
	row.push_back(4);
	vec.push_back(row);
	row.clear();

	row.push_back(5);
	row.push_back(6);
	row.push_back(7);
	row.push_back(8);
	vec.push_back(row);
	row.clear();

	row.push_back(9);
	row.push_back(10);
	row.push_back(11);
	row.push_back(12);
	vec.push_back(row);
	row.clear();

	row.push_back(13);
	row.push_back(14);
	row.push_back(15);
	row.push_back(16);
	vec.push_back(row);
	row.clear();

	Solution s;
	s.rotate(vec);
	
	for (int i=0; i<vec.size(); i++) {
		for (int j=0; j<vec[0].size(); j++) {
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
}
