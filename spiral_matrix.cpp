#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		vector<int> result;
		if (matrix.size() == 0) return result;
		int row = matrix.size(), col = matrix[0].size();
		
		for (int layer=0; layer<(min(row, col)+1)/2; layer++) {
			for (int j=layer; j<col-layer; j++) {
				result.push_back(matrix[layer][j]);	
			}	
			for (int i=layer+1; i<row-layer; i++) {
				result.push_back(matrix[i][col-1-layer]);
			}
			if (layer+1 >= row-layer) break;
			for (int j=col-1-1-layer; j>=layer; j--) {
				result.push_back(matrix[row-1-layer][j]);		
			}
			if (col-1-1-layer < layer) break;
			for (int i=row-1-1-layer; i>=layer+1; i--) {
				result.push_back(matrix[i][layer]);
			}
		}
		return result;
	}
};

int main()
{
	vector<int> row;
	vector<vector<int> > matrix;

/*	row.push_back(1);
	row.push_back(2);
	row.push_back(3);
	row.push_back(4);
	matrix.push_back(row);
	row.clear();

	row.push_back(5);
	row.push_back(6);
	row.push_back(7);
	row.push_back(8);
	matrix.push_back(row);
	row.clear();

	row.push_back(9);
	row.push_back(10);
	row.push_back(11);
	row.push_back(12);
	matrix.push_back(row);
	row.clear();*/

/*	row.push_back(1);
	row.push_back(2);
	row.push_back(3);
	matrix.push_back(row);
	row.clear();

	row.push_back(4);
	row.push_back(5);
	row.push_back(6);
	matrix.push_back(row);
	row.clear();

	row.push_back(7);
	row.push_back(8);
	row.push_back(9);
	matrix.push_back(row);
	row.clear();

	row.push_back(10);
	row.push_back(11);
	row.push_back(12);
	matrix.push_back(row);
	row.clear();*/

	row.push_back(7);
	matrix.push_back(row);
	row.clear();
	row.push_back(9);
	matrix.push_back(row);
	row.clear();
	row.push_back(6);
	matrix.push_back(row);
	row.clear();

	Solution s;
	row = s.spiralOrder(matrix);
	for (int i=0; i<row.size(); i++) {
		cout << row[i] << endl;
	}
}
