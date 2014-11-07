#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char> > &matrix) {
		if (matrix.size() == 0) return 0;
		
		int row = matrix.size();
		int col = matrix[0].size();
		vector<vector<int> > left(row, vector<int>(col, 0));
			
		for (int i=0; i<row; i++) {
			for (int j=0; j<col; j++) {
				if (matrix[i][j] == '1') {
					if (j == 0) left[i][j] = 1;
					else left[i][j] = left[i][j-1] + 1;
				}
			}
		}
		int max_area = 0;
		for (int i=0; i<row; i++) {
			for (int j=0; j<col; j++) {
				if (left[i][j] > 0) {
					int h = i;
					int l = left[i][j];
					while (h >= 0) {
						if (left[h][j] < l) l = left[h][j];
						if ( (i-h+1)*l>max_area ) max_area = (i-h+1)*l;
						h--;
					}
				}	
			}
		}
		return max_area;
	}
};

int main()
{
	vector<char> vec;
	vector<vector<char> > matrix;
	vec.push_back('0');
	vec.push_back('1');
	vec.push_back('1');
	vec.push_back('1');
	matrix.push_back(vec);
	vec.clear();

	vec.push_back('0');
	vec.push_back('1');
	vec.push_back('1');
	vec.push_back('1');
	matrix.push_back(vec);
	vec.clear();

	vec.push_back('1');
	vec.push_back('1');
	vec.push_back('0');
	vec.push_back('1');
	matrix.push_back(vec);
	vec.clear();

	vec.push_back('1');
	vec.push_back('1');
	vec.push_back('1');
	vec.push_back('1');
	matrix.push_back(vec);
	vec.clear();

	Solution s;
	cout << s.maximalRectangle(matrix) << endl;
}
